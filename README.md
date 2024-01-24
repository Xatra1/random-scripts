You can obtain all files by cloning the repository.  

To run ip.js, you will first need to run ``npm install node-fetch fs promisify-child-process`` for the main script.  
To run encodestr.js, you will first need to run ``npm install fs prompt-sync crypto``  
to run encodeweb.js, you will first need to run ``npm install fs http crypto``  

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
  
ip.js: Gets your IP using api.ipify.org, saves it to a file, reads the IP from the file, plays a success sound, and deletes the file. Execute with ``node ip.js``  
encodestr.js: Prompts the user to input a string and then encodes that string in Base64, while giving the option to write that string to a file, calculate the MD5 hash of the file, and encode that as well. Execute with ``node encodestr.js``
encodeweb.js: An HTTPS server that has the same functionality as encodestr.js. Any string that is sent to it via post data gets returned as an encoded MD5 hash.  
Shell Scripts/ipsuccess.sh: The beep sound ip.js uses, plays using your motherboard's onboard speaker.  
Shell Scripts/beep.sh: Plays a short jingle using your motherboard's onboard speaker.  
Shell Scripts/beeplong.sh: Same as beep.sh, with 4 more tones.
