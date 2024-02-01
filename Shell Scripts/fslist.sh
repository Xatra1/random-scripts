if [ -f ./fsout.log ]; then
echo Removing existing fsout.log
rm fsout.log
fi
echo Regular users do not have permission to read certain parts of the file system. This command needs to be run as root to fully list everything, which may require your password.
read -p 'Do you want to run as root? (y/n/c): ' choice
case $choice in
[yY]*) echo 'This may take a while.' && echo Note: Not even root has permissions to access certain files. && sleep 2 && sudo dir -AR / 2>&1 | tee fsout.log && echo Done! Output saved to fsout.log && echo Console will be cleared momentarily.;;
[nN]*) echo 'This may take a while.' && sleep 2 && dir -AR / 2>&1 | tee fsout.log && echo Done! Output saved to fsout.log && echo Console will be cleared momentarily.;;
[cC]*) echo 'Cancelled. Console will be cleared momentarily.' ;;
*) exit ;;
esac
sleep 2
clear