#include "Ejercicio03.h"
#include "Node.h"
#include <unordered_map>

template<typename T>
Node<T>* Ejercicio03::copyList(Node<T>* head) {
    if (head == nullptr) return nullptr;

    Node<T>* current = head;

    // Paso 1: Hacer copia de cada nodo y colocar cada nodo clonado justo después del nodo original.
    while (current != nullptr) {
        Node<T>* copy = new Node<T>(current->val);
        copy->next = current->next;
        current->next = copy;
        current = copy->next;
    }

    // Paso 2: Asignar punteros random.
    current = head;
    while (current != nullptr) {
        if (current->random != nullptr) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    // Paso 3: Separar las dos listas.
    Node<T>* dummy = new Node<T>(0);
    Node<T>* copy = dummy;
    current = head;
    while (current != nullptr) {
        copy->next = current->next;
        current->next = current->next->next;
        copy = copy->next;
        current = current->next;
    }

    // El nodo cabeza de la lista clonada
    Node<T>* clonedHead = dummy->next;
    delete dummy; // Eliminar el nodo dummy.
    return clonedHead;
}

// Es necesario instanciar la función para los tipos con los que se va a trabajar
// ya que estamos definiendo la función en un archivo .cpp y es un template.
template Node<int>* Ejercicio03::copyList<int>(Node<int>* head);