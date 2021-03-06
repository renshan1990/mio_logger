/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: renshan <1005110700@qq.com>                                  |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_MIO_LOGGER_H
#define PHP_MIO_LOGGER_H

extern zend_module_entry mio_logger_module_entry;
#define phpext_mio_logger_ptr &mio_logger_module_entry

#define PHP_MIO_LOGGER_VERSION "1.0.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_MIO_LOGGER_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_MIO_LOGGER_API __attribute__ ((visibility("default")))
#else
#	define PHP_MIO_LOGGER_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:

ZEND_BEGIN_MODULE_GLOBALS(mio_logger)
	zend_long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(mio_logger)
*/

/* Always refer to the globals in your function as MIO_LOGGER_G(variable).
   You are encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/
#define MIO_LOGGER_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(mio_logger, v)

#if defined(ZTS) && defined(COMPILE_DL_MIO_LOGGER)
ZEND_TSRMLS_CACHE_EXTERN()
#endif
	
/*
 *	Define the reteurn value
*/
#define OPEN_FAILURE	-2
#define WRITE_FAILURE	-1
#define LOG_SUCCESS		0

/*
 *	Define Log Level
*/
#define MIO_EMERGENCY	"EMERGENCY"
#define MIO_ALERT		"ALERT"
#define MIO_CRITICAL	"CRITICAL"
#define MIO_ERROR		"ERROR"
#define MIO_NOTICE		"NOTICE"
#define MIO_WARNING		"WARNING"
#define MIO_INFO		"INFO"
#define MIO_DEBUG		"DEBUG"

/*
 *	Define line feed
*/
#ifdef PHP_WIN32
#define LINE_FEED "\r\n"
#else
#define LINE_FEED "\n"
#endif



#endif	/* PHP_MIO_LOGGER_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
