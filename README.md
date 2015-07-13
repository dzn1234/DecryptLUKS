# cryptsetup_crack
crack the cryptsetup format's passphase

Compile:
       gcc  -O2  -lcryptsetup  cryptsetup_crack.c  -o  cryptsetup_crack
       
Run:
      ./cryptsetup_crack  /dev/sdb?  wordlist_name
      Like: ./cryptsetup_crack /dev/sdb3 wordlist.txt
      
For cryptsetup Install:
      sudo apt-get install libcryptsetup-dev
      
