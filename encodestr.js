const fs = require('fs');
const prompt = require('prompt-sync')();
const crypto = require('crypto');
const str = prompt('Please enter the string you would like to encode: ');
if (str != "") {
  console.log("Got it. Encoding this string: " + str);
  const encodedStr = btoa(str);
  var jsonStr = {
    "encodedString": encodedStr
  };
  console.log("Encoded string: " + encodedStr);
  const hashPrmpt = prompt('Would you like the string to be encoded further? (y/n) ')
  if (hashPrmpt == "y") {
    console.log("Writing string to string.json...");
    fs.writeFile('string.json', JSON.stringify(jsonStr), function () {
      fs.readFile('string.json', function (err, data) {
        if (err) {
          console.log(err);
          return process.exit()
        }
        console.log("Calculating the MD5 hash of string.json...");
        data = JSON.parse(data);
        let md5 = crypto.createHash("md5");
        md5.update(data.encodedString);
        let hash = md5.digest('hex');
        hash = btoa(hash);
        console.log('Encoded MD5 Hash: ' + hash);
        fs.unlink('string.json', function () {
          process.exit();
        });
      });
    });
  }
}
else console.log("You didn't input anything!");
process.on('exit', function (code) {
  return console.log("Process exited with code " + code);
})
