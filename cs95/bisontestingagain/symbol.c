#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "node.h"
#include "symbol.h"

int symbol_table_num_errors;

void symbol_initialize_table(struct symbol_table *table) {
  table->variables = NULL;
}

/**********************************************
 * WALK PARSE TREE AND ADD SYMBOLS INTO TABLE *
 **********************************************/
/*
 * This function is used to retrieve a symbol from a table.
 */
struct symbol *symbol_get(struct symbol_table *table, char name[]) {
  struct symbol_list *iter;
  for (iter = table->variables; NULL != iter; iter = iter->next) {
    if (!strcmp(name, iter->symbol.name)) {
      return &iter->symbol;
    }
  }
  return NULL;
}

struct symbol *symbol_put(struct symbol_table *table, char name[]) {
  struct symbol_list *symbol_list;

  symbol_list = malloc(sizeof(struct symbol_list));
  assert(NULL != symbol_list);

  strncpy(symbol_list->symbol.name, name, MAX_IDENTIFIER_LENGTH);
  symbol_list->symbol.result.type = NULL;
  symbol_list->symbol.result.ir_operand = NULL;

  symbol_list->next = table->variables;
  table->variables = symbol_list;

  return &symbol_list->symbol;
}

void symbol_add_from_identifier(struct symbol_table *table, struct node *identifier) {
  struct symbol *symbol;
  assert(NODE_IDENTIFIER == identifier->kind);

  symbol = symbol_get(table, identifier->data.identifier.name);
  if (NULL == symbol) {
    symbol = symbol_put(table, identifier->data.identifier.name);
  }
  identifier->data.identifier.symbol = symbol;
}

void symbol_add_from_expression(struct symbol_table *table, struct node *expression);

void symbol_add_from_binary_operation(struct symbol_table *table, struct node *binary_operation) {
  assert(NODE_BINARY_OPERATION == binary_operation->kind);

  symbol_add_from_expression(table, binary_operation->data.binary_operation.left_operand);
  symbol_add_from_expression(table, binary_operation->data.binary_operation.right_operand);
}

void symbol_add_from_expression(struct symbol_table *table, struct node *expression) {
  switch (expression->kind) {
    case NODE_BINARY_OPERATION:
      symbol_add_from_binary_operation(table, expression);
      break;
    case NODE_IDENTIFIER:
      symbol_add_from_identifier(table, expression);
    case NODE_NUMBER:
      break;
    default:
      assert(0);
      break;
  }
}
void symbol_add_from_expression_statement(struct symbol_table *table, struct node *expression_statement) {
  assert(NODE_EXPRESSION_STATEMENT == expression_statement->kind);

  symbol_add_from_expression(table, expression_statement->data.expression_statement.expression);
}

void symbol_add_from_statement_list(struct symbol_table *table, struct node *statement_list) {
  assert(NODE_STATEMENT_LIST == statement_list->kind);

  if (NULL != statement_list->data.statement_list.init) {
    symbol_add_from_statement_list(table, statement_list->data.statement_list.init);
  }
  symbol_add_from_expression_statement(table, statement_list->data.statement_list.statement);
}

/***********************
 * PRINT SYMBOL TABLES *
 ***********************/

void symbol_print_table(FILE *output, struct symbol_table *table) {
  struct symbol_list *iter;

  fputs("symbol table:\n", output);

  for (iter = table->variables; NULL != iter; iter = iter->next) {
    fprintf(output, "  variable: %s$%p\n", iter->symbol.name, (void *)&iter->symbol);
  }
  fputs("\n", output);
}
