You can obtain all files by cloning the repository.  

To run ip.js, you will first need to run ``npm install node-fetch fs promisify-child-process`` for the main script.  
  
For the beep scripts, you will need to perform the following:  
``sudo apt install beep``  
``sudo nano /etc/modprobe.d/blacklist.conf``  
Comment out (put a # in front of) the following lines:  
  ``blacklist snd_pcsp``  
  ``blacklist pcspkr``  
Save and exit by hitting Ctrl+S and Ctrl+X.    
``sudo usermod -aG input ${USER}``  
``reboot 0``  
After the reboot is completed, the tones should play successfully.  
  
ip.js: Gets your IP using api.ipify.org, saves it to a file, reads the IP from the file, plays a success sound, and deletes the file. Execute with ``node ip.js``  
Shell Scripts/ipsuccess.sh: The beep sound ip.js uses, plays using your motherboard's onboard speaker.  
Shell Scripts/beep.sh: Plays a short jingle using your motherboard's onboard speaker.  
Shell Scripts/beeplong.sh: Same as beep.sh, with 4 more tones.
