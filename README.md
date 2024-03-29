You can obtain all files by cloning the repository.  

To run **ip.js**, you will first need to run ``npm install node-fetch fs promisify-child-process`` for the main script.  
To run **encodestr.js**, you will first need to run ``npm install fs prompt-sync crypto``.  
to run **encodeweb.js**, you will first need to run ``npm install fs http crypto``.  
To compile **C/example.c** into an executable program, you will first need to run ``make && make clean`` in the same directory as ``example.c``.  
To compile **C/encrypt.c** into an executable program, you will first need to run ``gcc -c encrypt.c -o encrypt`` in the same directory as ``encrypt.c``.  

**These steps are not required if you are not using Ubuntu.**  
For the beep scripts, you will need to perform the following in a terminal:  
``sudo apt install beep``  
``sudo nano /etc/modprobe.d/blacklist.conf``  
Comment out (put a # in front of) the following lines:  
  ``blacklist snd_pcsp``  
  ``blacklist pcspkr``  
Save and exit by hitting Ctrl+S and Ctrl+X.    
Note: it is recommended to restore the original state of these lines once you're done using the scripts.  
``sudo usermod -aG input ${USER}``  
``reboot``  
After the reboot is completed, the tones should play successfully.    
  
**ip.js:** Gets your IP using api.ipify.org, saves it to a file, reads the IP from the file, plays a success sound, and deletes the file. Execute with ``node ip.js``.  
**encodestr.js:** Prompts the user to input a string and then encodes that string in Base64, while giving the option to write that string to a file, calculate the MD5 hash of the file, and encode that as well. Execute with ``node encodestr.js``.  
**encodeweb.js:** An HTTP server that has the same functionality as encodestr.js. Any string that is sent to it via post data gets returned as an encoded MD5 hash. Listens on port 9000 by default, but you can modify this by changing the value on line 4. Execute with ``node encodeweb.js``.  
**shellscripts/ipsuccess.sh:** The beep sound ip.js uses, plays using your motherboard's onboard speaker. Execute with ``bash ipsuccess.sh``.  
**shellscripts/beep.sh:** Plays a short jingle using your motherboard's onboard speaker. Execute with ``bash beep.sh``.  
**shellscripts/beeplong.sh:** Same as beep.sh, with 4 more tones. Execute with ``bash beeplong.sh``.  
**shellscripts/fslist.sh:** Lists every file and folder on your filesystem and outputs to fsout.log, with optional root access to allow for listing additional files. fsout.log will then be automatically opened in a text editor. Execute with ``bash fslist.sh``.  
**C/example.c:** Lists a bunch of information and outputs it to logs/log.txt, optionally outputting it to stdout as well. Can be executed by typing the filepath of the compiled executable into a terminal.  
**C/encrypt.c:** An encryption script that uses the key listed in 'key.txt' to encrypt the file 'original.txt', and can also decrypt 'results/cryptic.txt' using the same key. All outputs go into the newly created 'results' directory. Can be executed by typing the filepath of the compiled executable into a terminal. (This program will do nothing if executed using a different method)  
