typedef struct endereco
{
  char rua[50], cidade[50], estado[50];
  int numero;
} endereco;

typedef struct cliente
{
  int cod;
  char nome[50], telefone[25];
  endereco ender;
} cliente;

void ler_cliente(cliente cliente_arr[], int n)
{
  int i;

  for (i = 0; i < n; i++)
  {
    scanf("%d", &cliente_arr[i].cod);
    scanf(" %[^\n]s", cliente_arr[i].nome);
    scanf(" %[^\n]s", cliente_arr[i].ender.rua);
    scanf(" %[^\n]s", cliente_arr[i].ender.estado);
    scanf(" %[^\n]s", cliente_arr[i].ender.cidade);
    scanf(" %d", &cliente_arr[i].ender.numero);
    scanf(" %[^\n]s", cliente_arr[i].telefone);
  }
}

void buscar_cliente(cliente cliente_arr[], int n)
{
  int id;
  scanf("%d", &id);

  int i;
  for (i = 0; i < n; i++)
  {
    cliente cliente = cliente_arr[i];

    if (cliente.cod != id)
      continue;

    printf("%d - %s\n", cliente.cod, cliente.nome);
    printf("%s, %d\n", cliente.ender.rua, cliente.ender.numero);
    printf("%s - %s\n", cliente.ender.cidade, cliente.ender.estado);
    printf("Tel: %s", cliente.telefone);
  }
}

int main(void)
{
  cliente pessoas[3];
  ler_cliente(pessoas, 3);
  buscar_cliente(pessoas, 3);
}