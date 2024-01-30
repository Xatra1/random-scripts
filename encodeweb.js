const http = require('http');
const fs = require('fs');
const crypto = require('crypto');
const port = 9000;
var msg;
const requestListener = function (req, res) {
  req.on('data', chunk => {
    const jsonChunk = { "string": JSON.stringify(chunk) }
    encode(jsonChunk);
  })
  res.setHeader('Content-Type', 'text/json');
  res.writeHead(200);
  req.on('end', () => {
    console.log(msg);
    if (msg == undefined) res.end("An error has occurred when processing your request. Please try again." + "\n");
    else res.end(msg);
  })
}
const server = http.createServer(requestListener);
server.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
function encode(jsonChunk) {
  fs.writeFile('chunk.json', JSON.stringify(jsonChunk), function () {
    fs.readFile('chunk.json', function (err, data) {
      if (err) throw (err);
      data = JSON.parse(data);
      let md5 = crypto.createHash('md5');
      md5.update(data.string);
      let hash = md5.digest('hex');
      hash = btoa(hash);
      chunk = hash;
      fs.unlink('chunk.json', function () {
        msg = chunk + "\n";
        return msg;
      });
    });
  });
}