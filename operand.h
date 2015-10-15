/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: krakjoe                                                      |
  +----------------------------------------------------------------------+
*/

/* $Id$ */
#ifndef HAVE_INSPECTOR_OPERAND_H
#define HAVE_INSPECTOR_OPERAND_H
typedef struct _php_inspector_operand_t {
	zval node;
	uint32_t which;
	zend_uchar type;
	znode_op *op;
	zend_object std;
} php_inspector_operand_t;

zend_object_handlers php_inspector_operand_handlers;
zend_class_entry *php_inspector_operand_ce;

#define php_inspector_operand_fetch_from(o) ((php_inspector_operand_t*) (((char*)o) - XtOffsetOf(php_inspector_operand_t, std)))
#define php_inspector_operand_fetch(z) php_inspector_operand_fetch_from(Z_OBJ_P(z))
#define php_inspector_operand_this() php_inspector_operand_fetch(getThis())

void php_inspector_operand_destroy(zend_object *object);
void php_inspector_operand_construct(zval *object, zval *node, uint32_t which, zend_uchar type, znode_op *operand);
zend_object* php_inspector_operand_create(zend_class_entry *ce);

PHP_METHOD(Operand, isUnused);
PHP_METHOD(Operand, isExtendedTypeUnused);
PHP_METHOD(Operand, isCompiledVariable);
PHP_METHOD(Operand, isTemporaryVariable);
PHP_METHOD(Operand, isVariable);
PHP_METHOD(Operand, isConstant);
PHP_METHOD(Operand, isJumpTarget);
PHP_METHOD(Operand, getWhich);
PHP_METHOD(Operand, getValue);
PHP_METHOD(Operand, getName);
PHP_METHOD(Operand, getNumber);
#endif