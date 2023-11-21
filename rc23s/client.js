const net = require('node:net');
const readline = require('node:readline/promises');
const { stdin: input, stdout: output } = require('node:process');

const rl = readline.createInterface({ input, output });

async function main() {
  const host = await rl.question('Qual o endereço do host que você deseja se conectar?');
  const port = await rl.question('Qual a porta que será usada pra conexão?');

  const client = net.createConnection({ port, host }, () => {
    console.log('Conectado ao servidor!! 🥵🥵');
    console.log('Escrevar as mensagens que você quer enviar, para sair digite .exit');
  });

  client.on('end', () => {
    console.log('Disconectado do servidor 🙁🙁');
  })

  while (true) {
    const msg = await rl.question();

    if (msg === '.exit') {
      break;
    }

    client.write('msg');
  }

  client.end();
}

main();

