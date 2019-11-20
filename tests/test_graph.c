#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



#include "graph.h"
#include "linked_list.h"



void test_graph_has_vertice() {
    graph *graph = new_graph();

    insert_vertice(graph, 1);

    assert_true(is_vertice(graph, 1));
    assert_false(is_vertice(graph, 2));

    free_graph(graph->head);
}


/* Test the color property of graph_node */
void test_has_uncolored_vertice() {
    graph *graph = new_graph();

    insert_vertice(graph, 1);

    assert_true(has_uncolored_vertice(graph));

    graph->head->color = 1;

    assert_false(has_uncolored_vertice(graph));

    free_graph(graph->head);
}


/* Take a colored graph and uncolor it */
void test_uncolor_colored_vertice() {
    graph *graph = new_graph();

    insert_vertice(graph, 1);

    graph->head->color = 1;
    assert_false(has_uncolored_vertice(graph));

    uncolor(graph);
    assert_true(has_uncolored_vertice(graph));

    free_graph(graph->head);
}


void test_color_vertice() {
    graph *graph = new_graph();

    insert_vertice(graph, 1);

    graph->head->color = 1;

    assert_false(has_uncolored_vertice(graph));

    free_graph(graph->head);
}


void test_get_node_by_number() {
    graph *graph = new_graph();

    insert_vertice(graph, 1);

    struct graph_node *vertice = get_node(graph->head, 1);

    assert_true(vertice->vertice == 1);

    free_graph(graph->head);
}


void test_vertice_adjacents_have_same_color() {
    graph *graph = new_graph();

    insert_vertice(graph, 1);
    insert_vertice(graph, 2);

    insert_arest(graph, 1, 2);

    get_node(graph->head, 2)->color = 2;

    assert_true(vertice_adjacents_has_color(graph, &(get_node(graph->head, 1)->adjacents), 2));
    assert_false(vertice_adjacents_has_color(graph, &(get_node(graph->head, 1)->adjacents), 1));

    free_graph(graph->head);
}


void test_vertice_is_uncolored() {
    graph *graph = new_graph();
    uncolor(graph);

    insert_vertice(graph, 1);

    assert_true(vertice_is_uncolored(graph->head));

    graph->head->color = 1;

    assert_false(vertice_is_uncolored(graph->head));
}


void test_color_graph_with() {
    graph *graph = new_graph();
    uncolor(graph);

    insert_vertice(graph, 1);
    insert_vertice(graph, 2);

    color_graph_with(graph, 1);

    assert_int_equal(get_node(graph->head, 2)->color, 1);
    assert_int_equal(get_node(graph->head, 1)->color, 1);

    uncolor(graph);
    insert_arest(graph, 1, 2);
    color_graph_with(graph, 1);

    assert_int_equal(get_node(graph->head, 2)->color, 1);
    assert_int_equal(get_node(graph->head, 1)->color, 0);

    free_graph(graph->head);
}



int main(void) {

    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_graph_has_vertice),
        cmocka_unit_test(test_has_uncolored_vertice),
        cmocka_unit_test(test_uncolor_colored_vertice),
        cmocka_unit_test(test_color_vertice),
        cmocka_unit_test(test_get_node_by_number),
        cmocka_unit_test(test_vertice_adjacents_have_same_color),
        cmocka_unit_test(test_vertice_is_uncolored),
        cmocka_unit_test(test_color_graph_with),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
