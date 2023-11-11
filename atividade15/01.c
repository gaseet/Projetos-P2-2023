struct horario {
    int hora;
    int minuto;
    int segundo;
};

struct data {
    int dia;
    int mes;
    int ano;
};

struct compromisso {
    struct horario compromisso_horario;
    struct data compromisso_data;
    char descricao[100];
};