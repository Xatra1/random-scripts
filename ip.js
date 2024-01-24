const fetch = require('node-fetch');
const fs = require('fs');
const url = 'https://api.ipify.org/?format=json';
const method = { method: 'Get' };
const { exec } = require('promisify-child-process');
fetch(url, method)
	.then(res => res.json())
	.then((json) => {
		fs.writeFile('ip.json', JSON.stringify(json), function (err) {
			if (err) return console.log(err);
			console.log('File saved. Reading...')
			read();
		})
	})
function read() {
	fs.readFile('ip.json', function (err, data) {
		if (err) return console.log(err);
		data = JSON.parse(data);
		console.log('Your IP is ' + data.ip);
		let beep = exec('sh "./Shell Scripts/ipsuccess.sh"',
			(err, stderr) => {
				if (err != null) {
					console.log('Error when playing success sound: ' + stderr)
					console.log('If the error above states that "beep" is not found, please run "sudo apt install beep", reboot, and try again.');
				}
				fs.unlink('ip.json', function () {
					console.log('File removed.');
				});
			});
	})
}
