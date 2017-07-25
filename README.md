# cryptsetup_crack
crack the LUKS(Linux Unified Key Setup) Disk's passphase

Compile:
       gcc  -O2  -lcryptsetup  decrypt_luks.c  -o  decrypt_luks

Run:
       ./decrypt_luks  /dev/sdb?  wordlist_name

Like: ./decrypt_luks /dev/sdb3 wordlist.txx

For cryptsetup Install:
       sudo apt-get install libcryptsetup-dev
      
