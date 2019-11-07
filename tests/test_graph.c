#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdbool.h>
#include <assert.h>

#include "graph.h"
#include "linked_list.h"



void test_graph_has_vertice() {
    graph *graph = new_graph();

    insert_vertice(graph, 1);

    assert(is_vertice(graph, 1));
    assert(!(is_vertice(graph, 2)));
}


/* Test the color property of graph_node */
void test_has_uncolored_vertice() {
    graph *graph = new_graph();

    insert_vertice(graph, 1);
    
    assert_true(has_uncolored_vertice(graph));

    graph->head->color = 1;

    assert_false(has_uncolored_vertice(graph));

    free_graph(graph);
}


/* Take a colored graph and uncolor it */
void test_uncolor_colored_graph() {
    graph *graph = new_graph();
    
    insert_vertice(graph, 1);
    
    graph->head->color = 1;

    uncolor(graph);
    assert_true(has_uncolored_vertice(graph));
}


void test_color_vertice() {
    graph *graph = new_graph();
    
    insert_vertice(graph, 1);
    color_vertice(graph->head, 1);

    assert_false(has_uncolored_vertice(graph));
}


void test_get_node_by_number() {
    graph *graph = new_graph();
    
    insert_vertice(graph, 1);
    insert_vertice(graph, 2);
    insert_vertice(graph, 3);
    insert_vertice(graph, 4);
    
    struct graph_node *vertice = get_node(graph->head, 2);

    assert_int_equal(vertice->vertice, 2);

}


void test_if_vertice_adjacents_have_same_color() {
    graph *graph = new_graph();
    
    insert_vertice(graph, 1);
    insert_vertice(graph, 2);
    insert_vertice(graph, 3);

    insert_arest(graph, 1, 2);
    insert_arest(graph, 1, 3);
    
    color_vertice(get_node(graph->head, 2), 1);
    color_vertice(get_node(graph->head, 3), 2);
    
    assert_true(vertice_adjacents_has_color(graph, get_node(graph->head, 1), 1));
    assert_true(vertice_adjacents_has_color(graph, get_node(graph->head, 1), 2));
    assert_false(vertice_adjacents_has_color(graph, get_node(graph->head, 1), 3));

}



int main(void) {
    
    /*
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_graph_has_vertice),
        cmocka_unit_test(test_has_uncolored_vertice),
        cmocka_unit_test(test_uncolor_colored_graph),
        cmocka_unit_test(test_color_vertice),
        cmocka_unit_test(test_get_node_by_number),
        cmocka_unit_test(test_if_vertice_adjacents_have_same_color),

    };
    return cmocka_run_group_tests(tests, NULL, NULL);
    */
}
