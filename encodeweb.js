const http = require('http');
const fs = require('fs');
const crypto = require('crypto');
const port = 9000;
var chunk;
const requestListener = function (req, res) {
  req.on('data', chunk => {
    const jsonChunk = { "string": JSON.stringify(chunk) }
    encode(jsonChunk);
  })
  res.setHeader('Content-Type', 'text/json');
  res.writeHead(200);
  req.on('end', () => {
    console.log(chunk);
    if (chunk == undefined) res.end('No POST data was sent to the server. Please try again.');
    else res.end(chunk);
  })
}
const server = http.createServer(requestListener);
server.listen(port, () => {
  console.log(`Server is listening on port ${port}`);
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
        return chunk;
      });
    });
  });
}