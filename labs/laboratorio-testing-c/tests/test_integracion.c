#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento(void){

    printf("\ntest compra con descuento\n");
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Pan", 200, 3};
    Producto p2 = {"Leche", 350, 2};
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);

    ASSERT_IGUAL(1300, carrito_total(&c));


    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));



}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(void){

    printf("\nTest agregar hasta llenar\n");

    Carrito c;
    carrito_init(&c);
    
    Producto p1 = {"Leche", 350, 1};
    Producto p2 = {"Birra", 350, 1};
    Producto p3 = {"Bondiola", 350, 1};
    Producto p4 = {"Milanesas", 350, 1};
    Producto p5 = {"Mondongo", 350, 1};


    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    carrito_agregar(&c, p3);
    carrito_agregar(&c, p4);

    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
    ASSERT_IGUAL(0, carrito_agregar(&c, p5));
    
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));

}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
