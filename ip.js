const fetch = require('node-fetch');
const fs = require('fs');
const url = 'https://api.ipify.org/?format=json';
const method = { method: "Get" };
fetch(url, method)
    .then(res => res.json())
    .then((json) => {
        fs.writeFile('ip.json', JSON.stringify(json), function (e) {
            if (e) {
                return console.log(e);
            }
            console.log('File saved. Reading...')
            read();
        })
    })
function read() {
    fs.readFile('ip.json', function (e, data) {
        if (e) {
            return console.log(e);
        }
        data = JSON.parse(data);
        console.log("Your IP is " + data.ip);
        fs.unlink('ip.json', function () {
            console.log("File removed.");
        })
    })
}
