/*Общая суть такова, что нужно пробежаться в цикле по исходному списку и для каждого элемента создать новую копию.
Создаёт новый список идентичный данному, вернёт указатель на первый узел нового списка*/

node* my_copy(node* first){
    assert(first != NULL);
    node i_ptr = first;
    node cp_ptr = new node(i_ptr->item,i_ptr->next)
    
    node new_first = cp_ptr;
    
    while( i_ptr->next != NULL ){
    
        node cp_ptr->next = new node(i_ptr->next->item,i_ptr->next->next);
        
        i_ptr = i_ptr->next;
        cp_ptr = cp_ptr->next;
        
    }
    
    return new_first;
}