#include <stdio.h>
#include <string.h>

#include <libcryptsetup.h>

int main(int argc, char **argv)
{
    struct crypt_device *cd = NULL;
    const char *data_device = NULL;
    const char *activated_name = "cryptsetup_mount_name";
    const char* header_device;
    uint32_t flags = 0;
    int r;

    if (argc < 2)
    {
        printf("Usage: ./cryptsetup_crack device_name wordlist_file_name\n\n");
        return 0;
    }

    header_device = argv[1];


    if ((r = crypt_init(&cd, header_device)))
        goto out;

    if ((r = crypt_load(cd, CRYPT_LUKS1, NULL)))
        goto out;


    if (!data_device && (crypt_get_data_offset(cd) < 8)) {//crypt_get_data_offset(cd)=4096
        goto out;
    }

    crypt_set_timeout(cd, 0); // 0
    crypt_set_password_retry(cd, 3); //3
    crypt_set_password_verify(cd, 0); //0

    crypt_set_iteration_time(cd, 100);

    do{
        char *key_file_name = argv[2];
        FILE *key_file;
        int len;
        char pass[256];

        key_file = fopen(key_file_name, "r");
        if(!key_file){
            printf("File open error\n");
            goto out;
        }
        
        for (;;)
        {
            memset(pass,0,sizeof(pass));
            fscanf(key_file,"%s",pass);

            len = strlen(pass);
            if(len < 1)
                break;
            printf("pass= %s len= %d\n",pass,len);

            r = crypt_activate_by_passphrase(cd,		/* crypt context */
                             activated_name,	/* device name to activate */
                             CRYPT_ANY_SLOT,/* which slot use (ANY - try all) */
                             pass, len,	/* passphrase */
                             flags); /* flags */
            if (r >= 0) {
                printf("\nFound Passphase! %s\n\n",pass);
                break;
            }
        }
        fclose(key_file);
    } while(0);

out:
    crypt_free(cd);
    return r;
}
