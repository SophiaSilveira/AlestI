#include <iostream>

using namespace std;

struct Node {
  char info;  
  Node *prev, *next;
  Node(int i) {  info = i;  prev = next = nullptr;  cout << "+ Node(" << info << ") criado..." << endl;  }
  ~Node() {  cout << "- Node(" << info << ") destruido..." << endl;  }
};

void adicionaInicio( Node **head, Node **tail, char letra){
    Node * node = new Node (letra);
    if ( *head == nullptr ) { *head = *tail = node; }
    else {
        node -> next = *head;
        (*head)->prev = node;
        *head = node;
    }
}

void adicionaFinal(Node **head, Node **tail, char letra){
    Node * node = new Node (letra);
    node->prev = *tail;
    (*tail)->next = node;
    *tail = node;
}

void adicionaIndice(Node **head, Node **tail, int indice, char letra){
    if(indice == 0) return adicionaInicio(head, tail, letra);

    Node *aux = *head;
    while(indice > 0 && aux != nullptr){
        aux = aux->next; 
        --indice;
    }

    if(aux == nullptr) return adicionaFinal(head, tail, letra);

    Node * node = new Node (letra);

    node-> prev = aux->prev;
    node->next = aux ;
    (aux->prev)->next = node;
    aux->prev = node;

}

bool removeInicio(Node **head, Node **tail){
    if ( *head == nullptr ) return false;

    Node *aux = *head ;
    *head = (*head)-> next;
    if ( *head == nullptr ) *tail = nullptr ;
    else (*head)-> prev = nullptr ;
        delete aux;

    return true;
}

bool removeFinal(Node **head, Node **tail){
    if ( *head == nullptr ) return false;

    Node * aux = *tail;
    *tail = (*tail)->prev;
    if ( *tail == nullptr ) *head = nullptr ;
    else (*tail)->next = nullptr ;
    delete aux;

    return true;
}

bool removeIndice(Node **head, Node **tail, int indice){
    if ( *head == nullptr ) return false;
    if(indice == 0){
        removeInicio(head, tail);
        return true;
    } 

    Node *aux = *head;
    while(indice > 0 && aux != nullptr){
        aux = aux->next; 
        --indice;
    }

    if(aux == nullptr) return false;

    if(aux == *tail) {
        removeFinal(head, tail);
        return true;
    }

    (aux->prev )->next = aux->next ;
    if ( aux -> next == nullptr ) *tail = aux->prev;
    else ( aux -> next )-> prev = aux->prev;
    delete aux;

    return true; 
}


int main(){

    Node *head = nullptr, *tail = nullptr; 
    char letra;
    char info;
    int indice;

    while(letra != '.'){

        cout << "|";  // Exibição a partir do início
        for (Node *aux = head; aux != nullptr; aux = aux->next)
            cout << aux->info << "|";
        cout << endl;
        
        cin >> letra;
        if(letra == '<'){
            cin >> info;
            adicionaInicio(&head, &tail, info);
        }
        else if(letra == '>'){
            cin >> info;
            adicionaFinal(&head, &tail, info);
        }
        else if(letra == '+'){
            cin >> indice >> info;

            adicionaIndice(&head, &tail, indice, info);

            cout << "+" << endl;
        }
        else if(letra == '{'){
            if(!removeInicio(&head, &tail))
                cout << "ERRO" << endl;
        }
        else if(letra == '}'){
            if(!removeFinal(&head, &tail))
                cout << "ERRO" << endl;
        }
        else if(letra == '-'){
            cin >> indice;

            if(!removeIndice(&head, &tail, indice))
                cout << "ERRO" << endl;
            else{
                cout << "+" << endl;
            }
        }
    }

    cout << "|";  // Exibição a partir do final
    for (Node *aux = tail; aux != nullptr; aux = aux->prev)
      cout << aux->info << "|";
    cout << endl;
    

    return 1;
}