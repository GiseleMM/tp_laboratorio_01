#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct
{
    int id;
    int valor;
} EDato;

int ordenarPorId(void* id1,void* id2);

int main()
{
    printf("TP4 \n");
    int retorno;

    EDato* unDato=(EDato*)malloc(sizeof(EDato));
    if(unDato==NULL)
    {
        exit(1);

    }
    unDato->id=33;
    unDato->valor=66;

/*ll_newLinkedList*/

    LinkedList* lista=ll_newLinkedList();


/* ll_len  */
    retorno=ll_len(lista);
    printf("ll_len( )retorna :%d por que la lista esta vacia \n",retorno);


/* ll_add */
    retorno=ll_add(lista,unDato);
    printf("ll_add( )retorna :%d . \n0 si agrego a la lista -1 si no pudo \n",retorno);
    retorno=ll_len(lista);
    printf("size despues de ll_add %d\n",retorno);


/* ll_get */
    EDato* auxiliar=NULL;
    auxiliar=(EDato*)ll_get(lista,0);
    if(auxiliar!=NULL)
    {
        printf("id : %d\n", auxiliar->id);
        printf("valor: %d\n",auxiliar->valor);
    }


/* ll_set */
    EDato* unDatoParaRemplazar=(EDato*)malloc(sizeof(EDato));
    if(unDatoParaRemplazar==NULL)
    {
        exit(1);
    }
    unDatoParaRemplazar->id=55;
    unDatoParaRemplazar->valor=105;

    ll_set(lista,0,unDatoParaRemplazar);
    //compruebo pidiendo el dato en esa posicion con ll_get

    auxiliar=(EDato*)ll_get(lista,0);
    if(auxiliar!=NULL)
    {
        printf("id : %d\n", auxiliar->id);
        printf("valor: %d\n",auxiliar->valor);
    }


/* ll-remove  */
    //utilizo removo para eliminar el unico elemento de la lista, por lo que cuando llame a ll_len el valor debe ser 0
    ll_remove(lista,0);
    retorno=ll_len(lista);
    printf("ll_len despues de ll_remove al unico elemento de la lista %d\n",retorno);


/*  ll_clear  */
    EDato* array=(EDato*)malloc(sizeof(EDato)*5);
    if(array!=NULL)
    {
        for(int i=0; i<5; i++)
        {
            (array+i)->id=i+1;
            (array+i)->valor=i;

        }
        for(int i=0; i<5; i++)
        {
            ll_add(lista,array+i);
        }
        retorno=ll_len(lista);
        printf("ll_len despues de cargar 5 elemntos con ll_add :%d \n",retorno);
        ll_clear(lista);
        retorno=ll_len(lista);
        printf("ll_len despues de utilizar ll_clear  :%d \n",retorno);

    }

/* ll_isEmpty */
    retorno=ll_isEmpty(lista);
    printf("ll_isEmpty sobre la lista vacia retorna %d \n",retorno);


/*ll_indexOf*/
    for(int i=0; i<5; i++)
    {
        (array+i)->id=i;
        (array+i)->valor=1+i;
        ll_add(lista,array+i);
    }
    auxiliar=(EDato*)ll_get(lista,3);
    //tendria que coincidir el indice de ll_get con ll_indexOf
    retorno=ll_indexOf(lista,auxiliar);
    printf("ll_index retorno el indice del elemento obtenido con ll_get(lista,3) :%d \n",retorno);

/* ll_push */
    EDato* datoPush=(EDato*)malloc(sizeof(EDato));
    if(datoPush!=NULL)
    {
        datoPush->id=99;
        datoPush->valor=100;
    }
    ll_push(lista,0,datoPush);
    retorno=ll_len(lista);
    printf("ll_len despues de ll_push(lista,0)%d", retorno );
    auxiliar=(EDato*)ll_get(lista,0);
    printf("ll_get(lista,0) retorno un puntero con los valores del nuevo elemento con push\n");
    if(auxiliar!=NULL)
    {
        printf("id : %d\n", auxiliar->id);
        printf("valor: %d\n",auxiliar->valor);
    }
/* ll_pop */
    auxiliar=(EDato*)ll_pop(lista,0);
    retorno=ll_len(lista);
    printf("ll_len despues de usar ll_pop(lista,0) devuelve:%d ",retorno);

    printf("el auxiliar que retorna ll_pop es el del indice 0  verifico mostrando campo\n");
    printf("id: %d valor: %d\n",auxiliar->id,auxiliar->valor);

/* ll_clone */
    LinkedList* listaClone=ll_clone(lista);
    retorno=ll_len(listaClone);
    printf("ll_clone(lista) y lo asigne a listaClone\n ");
    printf("ll_len(listaClone) tiene que ser  igual a lista original %d\n",retorno);

/* ll_sublist */
    LinkedList* listaSublist=ll_subList(listaClone,0,2);
    retorno=ll_len(listaSublist);
    printf("ll_sublist(listaClone,0,2 y lo asigno a listaSubList\n");
    printf("ll_len(listaSublist)tiene que ser de 2 elementos :%d\n",retorno);

/* ll_containsAll*/
    retorno=ll_containsAll(listaClone,listaSublist);
    printf("ll_containsAll(listaClone,listaSubList) retorna %d  ,por que es una sublista de listaClone \n",retorno);
    retorno=ll_containsAll(listaSublist,listaClone);
    printf("ll_containsAll(listaSublist,listaClone) retorna %d  ,por que es una sublista de listaClone \n",retorno);
/* ll_contains */
    retorno=ll_contains(listaClone,auxiliar);
    printf("ll_contains(listaClone,auxiliar) auxiliar es un puntero que se le asigno un dato eliminado con ll_pop\n");
    printf("ll_contains retorna %d\n",retorno);
    ll_push(listaClone,0,auxiliar);
    retorno=ll_contains(listaClone,auxiliar);
    printf("ll_contains retorna %d despues de ll_push(listaClone,0,auxiliar)\n",retorno);
    retorno=ll_len(listaClone);
    printf("ll_len(listaClone) retorna ahora %d\n",retorno);

/* ll_sort */
    LinkedList* listaOrdenar=ll_newLinkedList();
    EDato*auxOrdenar=NULL;
    EDato* datosParaOrdenar=(EDato*)malloc(sizeof(EDato)*10);
    if(datosParaOrdenar!=NULL)
    {
        for(int i=0;i<10;i++)
        {
            (datosParaOrdenar+i)->id=i;
            (datosParaOrdenar+i)->valor=10-i;
        }
        /*for(int i=0;i<10;i++)
        {
            printf("id: %d valor: %d\n",(datosParaOrdenar+i)->id,(datosParaOrdenar+i)->valor);
        }*/
    }
    for(int i=0;i<10;i++)
    {
        ll_add(listaOrdenar,datosParaOrdenar+i);
        auxOrdenar=(EDato*)ll_get(listaOrdenar,i);
        printf("id:%d valor: %d\n",auxOrdenar->id,auxOrdenar->valor);
    }
    ll_sort(listaOrdenar,ordenarPorId,0);
    printf("ll_sort(listaOrdenar,OrdenarPorId,0)\n");
    for(int i=0;i<ll_len(listaOrdenar);i++)
    {
        auxOrdenar=(EDato*)ll_get(listaOrdenar,i);
        printf("id:%d valor: %d\n",auxOrdenar->id,auxOrdenar->valor);
    }



/* ll_deleteLinkedList */
    ll_deleteLinkedList(listaOrdenar);
    ll_deleteLinkedList(lista);
    ll_deleteLinkedList(listaClone);
    ll_deleteLinkedList(listaSublist);
    free(datoPush);
    free(array);
    free(unDato);

    return 0;
}
int ordenarPorId(void* id1, void* id2)
{
    int resultadoComparcion=0;
    if(((EDato*)id1)->id > ((EDato*)id2)->id)
    {
        resultadoComparcion=1;
    }
    if(((EDato*)id1)->id < ((EDato*)id2)->id)
    {
        resultadoComparcion=-1;
    }
    //printf("resultado comparacion %d",resultadoComparcion);
    return resultadoComparcion;

}

