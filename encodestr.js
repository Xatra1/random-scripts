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
  const hashEncode = prompt('Would you like it to be encoded further? (y/n) ')
  if (hashEncode == "y") {
    fs.writeFile('string2.json', JSON.stringify(jsonStr), function () {
      fs.readFile('string2.json', function (err, data) {
        if (err) return console.log(err);
        data = JSON.parse(data);
        let md5 = crypto.createHash("md5");
        md5.update(data.encodedString);
        let hash = md5.digest('hex');
        hash = btoa(hash);
        console.log('Encoded MD5 Hash: ' + hash);
        fs.unlink('string2.json', function () {
          console.log("Files removed.");
        });
      });
    });
  }
}
else console.log("You didn't input anything!");