const net = require('node:net');
const readline = require('node:readline/promises');
const { stdin: input, stdout: output } = require('node:process');

const rl = readline.createInterface({ input, output });

async function messageSender(client) {
  while (true) {
    const msg = await rl.question("-> ");
    if (msg === '.exit') break;

    client.write(msg);
  }

  client.end();
  process.exit();
}

async function main() {
  const host = await rl.question('Qual o endereço do host que você deseja se conectar?\n');
  const port = await rl.question('Qual a porta que será usada pra conexão?\n');

  const client = net.createConnection({ port, host }, async () => {
    console.log('Conectado ao servidor!!');
    console.log('Escreva as mensagens que você quer enviar, para sair digite .exit\n');

    await messageSender(client);
    console.log("foi");
  });

  client.on('end', () => {
    console.log('Desconectado do servidor');
  })
}

main();

