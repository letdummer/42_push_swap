#include <assert.h>
#include <stdio.h>
#include "push_swap.h"

void print_stack(t_stack *stack);

// 🏗️ Teste de inserção na pilha
void test_add_to_top() {
	t_stack *stack = NULL;

	printf("\tTest: Add to top\n");
	add_to_top(&stack, 5);
	assert(stack != NULL);
	assert(stack->content == 5);
	print_stack(stack);

	add_to_top(&stack, 10);
	assert(stack->content == 10);
	print_stack(stack);
	printf("\n");
}

// 🏗️ Teste de remoção da pilha
void test_remove_top() {
	t_stack *stack = NULL;

	printf("\tTest: Remove top\n");
	add_to_top(&stack, 5);
	add_to_top(&stack, 10);

	print_stack(stack);
	t_stack *removed = remove_top(&stack);
	assert(removed != NULL);
	assert(removed->content == 10);
	free(removed);

	print_stack(stack);
	assert(stack->content == 5);
	printf("\n");
}

// 📏 Teste de tamanho da pilha
void test_ft_size_list() {
	t_stack *stack = NULL;

	printf("\tTest: Size list\n");
	add_to_top(&stack, 5);
	add_to_top(&stack, 10);

	assert(ft_size_list(stack) == 2);
	print_stack(stack);
	printf("\n");
}

// 📌 Teste de lista já ordenada
void test_sorted_list() {
	t_stack *stack = NULL;

	printf("\tTest: Sorted list\n");
	add_to_top(&stack, 3);
	add_to_top(&stack, 2);
	add_to_top(&stack, 1);

	print_stack(stack);
	ft_sort_three(&stack);
	print_stack(stack);

	assert(stack->content == 1);
	assert(stack->next->content == 2);
	assert(stack->next->next->content == 3);
	printf("\n");
}

// 📌 Teste de lista inversamente ordenada
void test_reverse_sorted_list() {
	t_stack *stack = NULL;

	printf("\tTest: Reverse sorted list\n");
	add_to_top(&stack, 1);
	add_to_top(&stack, 2);
	add_to_top(&stack, 3);

	print_stack(stack);
	ft_sort_three(&stack);
	print_stack(stack);

	assert(stack->content == 1);
	assert(stack->next->content == 2);
	assert(stack->next->next->content == 3);
	printf("\n");
}

// 📌 Teste de valores duplicados na pilha
void	test_duplicate_values()
{
    t_stack *stack = NULL;

    add_to_top(&stack, 2);
    add_to_top(&stack, 3);
    add_to_top(&stack, 3);

    printf("Before checking duplicates:\n");
    print_stack(stack);

    ft_check_duplicates(&stack);

    // Se houver duplicatas, evitamos ordenar a pilha
    if (!stack)
    {
        printf("Error detected, stopping test.\n");
        return;
    }

    printf("After checking duplicates:\n");
    print_stack(stack);

    ft_sort_three(&stack);

    printf("After sorting:\n");
    print_stack(stack);
}



// 📌 Teste de ordenação de 3 elementos
void test_ft_sort_three() {
	t_stack *stack = NULL;

	printf("\tTest: Sort three elements\n");
	add_to_top(&stack, 3);
	add_to_top(&stack, 1);
	add_to_top(&stack, 2);

	printf("Before sorting:\n");
	print_stack(stack);

	ft_sort_three(&stack);

	printf("After sorting:\n");
	print_stack(stack);

	assert(stack->content == 1);
	assert(stack->next->content == 2);
	assert(stack->next->next->content == 3);
	printf("\n");
}

// 📌 Teste de ordenação de 5 elementos
void test_ft_sort_five() {
	t_stack *a = NULL, *b = NULL;

	printf("\tTest: Sort five elements\n");
	add_to_top(&a, 5);
	add_to_top(&a, 1);
	add_to_top(&a, 4);
	add_to_top(&a, 2);
	add_to_top(&a, 3);

	printf("Before sorting:\n");
	print_stack(a);

	ft_sort_five(&a, &b);

	printf("After sorting:\n");
	print_stack(a);

	assert(a->content == 1);
	assert(a->next->content == 2);
	assert(a->next->next->content == 3);
	assert(a->next->next->next->content == 4);
	assert(a->next->next->next->next->content == 5);
	printf("\n");
}

void print_stack(t_stack *stack)
{
	printf("Stack: ");
	while (stack)
	{
		printf("%d -> ", stack->content);
		stack = stack->next;
	}
	printf("NULL\n");
}

int main() {
	test_add_to_top();
	test_remove_top();
	test_ft_size_list();
	test_ft_sort_three();
	test_ft_sort_five();
	test_sorted_list();
	test_reverse_sorted_list();
	test_duplicate_values();

	printf("✅ All tests passed!\n");
	return 0;
}
