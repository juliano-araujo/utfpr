const net = require('node:net');
const readline = require('node:readline/promises');
const { stdin: input, stdout: output } = require('node:process');

const server = net.createServer(c => {
  console.log('Cliente conectedo!');

  c.on('data', (data) => {
    console.log(`${c.address().address} > ${data.toString()}`)
  })

  c.on('end', () => {
    console.log('Morreu 💀')
  })
});

server.on('error', (err) => {
  throw err;
});

const rl = readline.createInterface({input, output});

async function main() {
  const port = await rl.question('Em qual porta o server será iniciado?\n')

  server.listen(port, () => {
    console.log('Server iniciado! Escutando...')
  });
}

main();