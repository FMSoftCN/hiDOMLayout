/*
 * This file was generated by LibCSS gen_parser 
 * 
 * Generated from:
 *
 * grid_template_columns:CSS_PROP_GRID_TEMPLATE_COLUMNS WRAP:css__parse_grid_template_columns_impl
 * 
 * Copyright (C) 2021 Beijing FMSoft Technologies Co., Ltd.
 */

#include <assert.h>
#include <string.h>

#include "bytecode/bytecode.h"
#include "bytecode/opcodes.h"
#include "parse/properties/properties.h"
#include "parse/properties/utils.h"

/**
 * Parse grid_template_columns
 *
 * \param c	  Parsing context
 * \param vector  Vector of tokens to process
 * \param ctx	  Pointer to vector iteration context
 * \param result  resulting style
 * \return CSS_OK on success,
 *	   CSS_NOMEM on memory exhaustion,
 *	   CSS_INVALID if the input is not valid
 *
 * Post condition: \a *ctx is updated with the next token to process
 *		   If the input is invalid, then \a *ctx remains unchanged.
 */
css_error css__parse_grid_template_columns(css_language *c,
		const parserutils_vector *vector, int *ctx,
		css_style *result)
{
	return css__parse_grid_template_columns_impl(c, vector, ctx, result, CSS_PROP_GRID_TEMPLATE_COLUMNS);
}
