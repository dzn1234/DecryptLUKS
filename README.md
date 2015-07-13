# cryptsetup_crack
crack the cryptsetup format's passphase
\n
Compile:
       gcc  -O2  -lcryptsetup  cryptsetup_crack.c  -o  cryptsetup_crack
\n
Run:
       ./cryptsetup_crack  /dev/sdb?  wordlist_name
\n
Like: ./cryptsetup_crack /dev/sdb3 wordlist.txx
\n
For cryptsetup Install:
       sudo apt-get install libcryptsetup-dev
      
