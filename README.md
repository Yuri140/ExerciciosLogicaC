# 🖥️ Exercícios de Lógica de Programação em C

Este repositório contém as soluções dos exercícios de **Lógica de Programação** desenvolvidos durante a disciplina.
Cada exercício foi implementado em linguagem **C**, com enunciado documentado no início de cada arquivo como comentário.

---

## 📂 Estrutura do Repositório

- Todos os códigos-fonte estão dentro da pasta [`src/`](./src).
- Cada exercício possui um arquivo independente com extensão `.c`.
- O enunciado do problema está descrito diretamente no início de cada código.

```
ExerciciosLogicaC/
├── README.md
└── src/
    ├── exercicio01.c
    ├── exercicio02.c
    └── ...
```

---

## 📑 Lista de Exercícios

1.  [Exercício 01](./src/exercicio01.c) – Maior e menor número digitado
2.  [Exercício 02](./src/exercicio02.c) – Média dos números pares e ímpares
3.  [Exercício 03](./src/exercicio03.c) – Somar algarismos de um número
4.  [Exercício 04](./src/exercicio04.c) – Somar positivos e negativos separadamente
5.  [Exercício 05](./src/exercicio05.c) – Números no intervalo [10, 50]
6.  [Exercício 06](./src/exercicio06.c) – Fatorial de um número
7.  [Exercício 07](./src/exercicio07.c) – Sistema bancário simples
8.  [Exercício 08](./src/exercicio08.c) – Função para somar dois números
9.  *(em breve...)*

---

## 🚀 Como compilar e executar

### Linux/MacOS

```bash
# Substitua exercicio01.c pelo exercício desejado.
gcc src/exercicio01.c -o exercicio01
./exercicio01
```

### Windows (MinGW instalado)

```bash
# Substitua exercicio01.c pelo exercício desejado.
gcc src/exercicio01.c -o exercicio01.exe
./exercicio01.exe
```

---

## 🌐 Suporte a caracteres especiais (UTF-8)

Para garantir que caracteres especiais (acentos, símbolos, etc.) sejam exibidos corretamente no terminal do Windows, é recomendado configurar o sistema para usar UTF-8 como página de código padrão:

### Configurando UTF-8 no Windows

1. **Método Temporário (para a sessão atual do CMD)**:
   ```
   chcp 65001
   ```

2. **Método Permanente através das Configurações do Windows**:
   - Abra as **Configurações do Windows** (tecla Windows + I)
   - Vá para **Hora e Idioma** → **Idioma e região**
   - Clique em **Configurações administrativas de idioma**
   - Na aba **Região**, clique em **Alterar localidade do sistema**
   - Marque a opção **Usar Unicode UTF-8 para suporte a idiomas em todo o mundo**
   - Clique em **OK** e reinicie o computador

---

### 📚 Objetivo do Repositório

Este repositório tem como finalidade:

- Registrar a evolução no aprendizado de C e lógica de programação;
- Manter os exercícios organizados em um só lugar;
- Servir como material de estudo e consulta futura;
- Expor boas práticas no uso de GitHub para projetos acadêmicos.

---

📌 **Observações**

- As soluções priorizam clareza e simplicidade, não otimização avançada.
- O repositório será atualizado conforme novos exercícios forem resolvidos.
- Sugestões de melhorias são sempre bem-vindas!

