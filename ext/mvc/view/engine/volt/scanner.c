/* Generated by re2c 0.13.5 on Sat Jan 11 18:49:23 2014 */
/* #line 1 "scanner.re" */

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "php_phalcon.h"
#include "mvc/view/engine/volt/scanner.h"

#define KKCTYPE unsigned char
#define KKCURSOR (s->start)
#define KKLIMIT (s->end)
#define KKMARKER q

void phvolt_rtrim(phvolt_scanner_token *token) {

	char *cursor, *removed_str;
	int i;
	char ch;

	if (token->len > 0) {

		cursor = token->value;
		cursor += (token->len - 1);
		for (i = token->len; i > 0; i--) {
			ch = (*cursor);
			if (ch == '\t' || ch == '\n' || ch == '\r' || ch == ' ' || ch == '\v') {
				cursor--;
				continue;
			}
			break;
		}

		removed_str = emalloc(i + 1);
		memcpy(removed_str, token->value, i);
		removed_str[i] = '\0';

		efree(token->value);
		token->value = removed_str;
		token->len = i;
	}

}

void phvolt_ltrim(phvolt_scanner_token *token) {

	char *cursor, *removed_str;
	int i;

	if (token->len > 0) {

		cursor = token->value;
		for (i = 0; i < token->len; i++) {
			char ch = (*cursor);
			if (ch == '\t' || ch == '\n' || ch == '\r' || ch == ' ' || ch == '\v') {
				cursor++;
				continue;
			}
			break;
		}

		removed_str = emalloc(token->len - i + 1);
		memcpy(removed_str, token->value + i, token->len - i);
		removed_str[token->len - i] = '\0';

		efree(token->value);
		token->value = removed_str;
		token->len = token->len - i;
	}

}

int phvolt_get_token(phvolt_scanner_state *s, phvolt_scanner_token *token) {

	unsigned char next, double_next;
	char *q = KKCURSOR, *start = KKCURSOR;
	int status = PHVOLT_SCANNER_RETCODE_IMPOSSIBLE;

	while (PHVOLT_SCANNER_RETCODE_IMPOSSIBLE == status) {

		if (s->mode == PHVOLT_MODE_RAW || s->mode == PHVOLT_MODE_COMMENT) {

			next = '\0';
			double_next = '\0';

			if (*KKCURSOR == '\n') {
				s->active_line++;
			}

			if (*KKCURSOR != '\0') {
				next = *(KKCURSOR + 1);
				if (next != '\0') {
					double_next = *(KKCURSOR + 2);
				}
			}

			if (*KKCURSOR == '\0' || (*KKCURSOR == '{' && (next == '%' || next == '{' || next == '#'))) {

				if (next != '#') {

					s->mode = PHVOLT_MODE_CODE;

					if (s->raw_buffer_cursor > 0) {

						token->opcode = PHVOLT_T_RAW_FRAGMENT;
						token->value = emalloc(sizeof(char) * s->raw_buffer_cursor + 1);
						memcpy(token->value, s->raw_buffer, s->raw_buffer_cursor);
						token->value[s->raw_buffer_cursor] = 0;
						token->len = s->raw_buffer_cursor;

						if (s->whitespace_control == 1) {
							phvolt_ltrim(token);
							s->whitespace_control = 0;
						}

						if (double_next == '-') {
							phvolt_rtrim(token);
						}

						s->raw_buffer_cursor = 0;
						q = KKCURSOR;
					} else {
						token->opcode = PHVOLT_T_IGNORE;
					}

				} else {

					while ((next = *(++KKCURSOR))) {
						if (next == '#' && *(KKCURSOR + 1) == '}') {
							KKCURSOR+=2;
							token->opcode = PHVOLT_T_IGNORE;
							return 0;
						} else {
							if (next == '\n') {
								s->active_line++;
							}
						}
					}

					return PHVOLT_SCANNER_RETCODE_EOF;
				}

				return 0;

			} else {

				if (s->raw_buffer_cursor == s->raw_buffer_size) {
					s->raw_buffer_size += PHVOLT_RAW_BUFFER_SIZE;
					s->raw_buffer = erealloc(s->raw_buffer, s->raw_buffer_size);
				}

				memcpy(s->raw_buffer+s->raw_buffer_cursor, KKCURSOR, 1);
				s->raw_buffer_cursor++;

				++KKCURSOR;
			}

		} else {

		
/* #line 177 "scanner.c" */
		{
			KKCTYPE kkch;
			unsigned int kkaccept = 0;
			static const unsigned char kkbm[] = {
				  0,  96,  96,  96,  96,  96,  96,  96, 
				 96, 104,  96,  96,  96, 104,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				104,  96,  32,  96,  96,  96,  96,  64, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				240, 240, 240, 240, 240, 240, 240, 240, 
				240, 240,  96,  96,  96,  96,  96,  96, 
				 96, 112, 112, 112, 112, 112, 112, 112, 
				112, 112, 112, 112, 112, 112, 112, 112, 
				112, 112, 112, 112, 112, 112, 112, 112, 
				112, 112, 112,  96,  16,  96,  96, 112, 
				 96, 112, 112, 112, 112, 112, 112, 112, 
				112, 112, 112, 112, 112, 112, 112, 112, 
				112, 112, 112, 112, 112, 112, 112, 112, 
				112, 112, 112,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
				 96,  96,  96,  96,  96,  96,  96,  96, 
			};

			kkch = *KKCURSOR;
			switch (kkch) {
			case 0x00:	goto kk70;
			case '\t':
			case '\r':
			case ' ':	goto kk66;
			case '\n':	goto kk68;
			case '!':	goto kk58;
			case '"':	goto kk27;
			case '%':	goto kk21;
			case '\'':	goto kk29;
			case '(':	goto kk44;
			case ')':	goto kk46;
			case '*':	goto kk34;
			case '+':	goto kk32;
			case ',':	goto kk42;
			case '-':	goto kk23;
			case '.':	goto kk40;
			case '/':	goto kk36;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto kk2;
			case ':':	goto kk62;
			case '<':	goto kk52;
			case '=':	goto kk54;
			case '>':	goto kk56;
			case '?':	goto kk64;
			case 'A':
			case 'a':	goto kk11;
			case 'B':
			case 'b':	goto kk13;
			case 'C':
			case 'c':	goto kk15;
			case 'D':
			case 'd':	goto kk18;
			case 'E':
			case 'e':	goto kk6;
			case 'F':
			case 'f':	goto kk7;
			case 'G':
			case 'H':
			case 'J':
			case 'K':
			case 'L':
			case 'P':
			case 'Q':
			case 'U':
			case 'V':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'g':
			case 'h':
			case 'j':
			case 'k':
			case 'l':
			case 'p':
			case 'q':
			case 'u':
			case 'v':
			case 'x':
			case 'y':
			case 'z':	goto kk31;
			case 'I':
			case 'i':	goto kk4;
			case 'M':
			case 'm':	goto kk14;
			case 'N':
			case 'n':	goto kk9;
			case 'O':
			case 'o':	goto kk12;
			case 'R':
			case 'r':	goto kk17;
			case 'S':
			case 's':	goto kk8;
			case 'T':
			case 't':	goto kk10;
			case 'W':
			case 'w':	goto kk16;
			case '[':	goto kk48;
			case '\\':	goto kk30;
			case ']':	goto kk50;
			case '{':	goto kk19;
			case '|':	goto kk60;
			case '}':	goto kk25;
			case '~':	goto kk38;
			default:	goto kk72;
			}
kk2:
			kkaccept = 0;
			kkch = *(KKMARKER = ++KKCURSOR);
			goto kk292;
kk3:
/* #line 178 "scanner.re" */
			{
			token->opcode = PHVOLT_T_INTEGER;
			token->value = estrndup(start, KKCURSOR - start);
			token->len = KKCURSOR - start;
			q = KKCURSOR;
			return 0;
		}
/* #line 325 "scanner.c" */
kk4:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) <= 'S') {
				if (kkch <= 'M') {
					if (kkch == 'F') goto kk278;
					goto kk100;
				} else {
					if (kkch <= 'N') goto kk280;
					if (kkch <= 'R') goto kk100;
					goto kk282;
				}
			} else {
				if (kkch <= 'm') {
					if (kkch == 'f') goto kk278;
					goto kk100;
				} else {
					if (kkch <= 'n') goto kk280;
					if (kkch == 's') goto kk282;
					goto kk100;
				}
			}
kk5:
/* #line 443 "scanner.re" */
			{
			token->opcode = PHVOLT_T_IDENTIFIER;
			token->value = estrndup(start, KKCURSOR - start);
			token->len = KKCURSOR - start;
			q = KKCURSOR;
			return 0;
		}
/* #line 356 "scanner.c" */
kk6:
			kkch = *++KKCURSOR;
			if (kkch <= 'X') {
				if (kkch <= 'M') {
					if (kkch == 'L') goto kk219;
					goto kk100;
				} else {
					if (kkch <= 'N') goto kk220;
					if (kkch <= 'W') goto kk100;
					goto kk221;
				}
			} else {
				if (kkch <= 'm') {
					if (kkch == 'l') goto kk219;
					goto kk100;
				} else {
					if (kkch <= 'n') goto kk220;
					if (kkch == 'x') goto kk221;
					goto kk100;
				}
			}
kk7:
			kkch = *++KKCURSOR;
			if (kkch <= 'O') {
				if (kkch == 'A') goto kk211;
				if (kkch <= 'N') goto kk100;
				goto kk212;
			} else {
				if (kkch <= 'a') {
					if (kkch <= '`') goto kk100;
					goto kk211;
				} else {
					if (kkch == 'o') goto kk212;
					goto kk100;
				}
			}
kk8:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk208;
			if (kkch == 'e') goto kk208;
			goto kk100;
kk9:
			kkch = *++KKCURSOR;
			if (kkch <= 'U') {
				if (kkch == 'O') goto kk201;
				if (kkch <= 'T') goto kk100;
				goto kk202;
			} else {
				if (kkch <= 'o') {
					if (kkch <= 'n') goto kk100;
					goto kk201;
				} else {
					if (kkch == 'u') goto kk202;
					goto kk100;
				}
			}
kk10:
			kkch = *++KKCURSOR;
			if (kkch == 'R') goto kk197;
			if (kkch == 'r') goto kk197;
			goto kk100;
kk11:
			kkch = *++KKCURSOR;
			if (kkch <= 'U') {
				if (kkch == 'N') goto kk184;
				if (kkch <= 'T') goto kk100;
				goto kk185;
			} else {
				if (kkch <= 'n') {
					if (kkch <= 'm') goto kk100;
					goto kk184;
				} else {
					if (kkch == 'u') goto kk185;
					goto kk100;
				}
			}
kk12:
			kkch = *++KKCURSOR;
			if (kkch == 'R') goto kk182;
			if (kkch == 'r') goto kk182;
			goto kk100;
kk13:
			kkch = *++KKCURSOR;
			if (kkch <= 'R') {
				if (kkch == 'L') goto kk172;
				if (kkch <= 'Q') goto kk100;
				goto kk173;
			} else {
				if (kkch <= 'l') {
					if (kkch <= 'k') goto kk100;
					goto kk172;
				} else {
					if (kkch == 'r') goto kk173;
					goto kk100;
				}
			}
kk14:
			kkch = *++KKCURSOR;
			if (kkch == 'A') goto kk167;
			if (kkch == 'a') goto kk167;
			goto kk100;
kk15:
			kkch = *++KKCURSOR;
			if (kkch <= 'O') {
				if (kkch == 'A') goto kk151;
				if (kkch <= 'N') goto kk100;
				goto kk152;
			} else {
				if (kkch <= 'a') {
					if (kkch <= '`') goto kk100;
					goto kk151;
				} else {
					if (kkch == 'o') goto kk152;
					goto kk100;
				}
			}
kk16:
			kkch = *++KKCURSOR;
			if (kkch == 'I') goto kk147;
			if (kkch == 'i') goto kk147;
			goto kk100;
kk17:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk141;
			if (kkch == 'e') goto kk141;
			goto kk100;
kk18:
			kkch = *++KKCURSOR;
			if (kkch <= 'O') {
				if (kkch == 'E') goto kk132;
				if (kkch <= 'N') goto kk100;
				goto kk133;
			} else {
				if (kkch <= 'e') {
					if (kkch <= 'd') goto kk100;
					goto kk132;
				} else {
					if (kkch == 'o') goto kk133;
					goto kk100;
				}
			}
kk19:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '%') goto kk126;
			if (kkch == '{') goto kk124;
/* #line 526 "scanner.re" */
			{
			token->opcode = PHVOLT_T_CBRACKET_OPEN;
			return 0;
		}
/* #line 507 "scanner.c" */
kk21:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '}') goto kk122;
/* #line 471 "scanner.re" */
			{
			token->opcode = PHVOLT_T_MOD;
			return 0;
		}
/* #line 516 "scanner.c" */
kk23:
			kkaccept = 1;
			kkch = *(KKMARKER = ++KKCURSOR);
			if (kkch <= '-') {
				if (kkch == '%') goto kk117;
				if (kkch >= '-') goto kk114;
			} else {
				if (kkch <= '=') {
					if (kkch >= '=') goto kk112;
				} else {
					if (kkch == '}') goto kk116;
				}
			}
kk24:
/* #line 456 "scanner.re" */
			{
			token->opcode = PHVOLT_T_SUB;
			return 0;
		}
/* #line 536 "scanner.c" */
kk25:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '}') goto kk110;
/* #line 531 "scanner.re" */
			{
			token->opcode = PHVOLT_T_CBRACKET_CLOSE;
			return 0;
		}
/* #line 545 "scanner.c" */
kk27:
			kkaccept = 2;
			kkch = *(KKMARKER = ++KKCURSOR);
			if (kkch >= 0x01) goto kk108;
kk28:
/* #line 642 "scanner.re" */
			{
			status = PHVOLT_SCANNER_RETCODE_ERR;
			break;
		}
/* #line 556 "scanner.c" */
kk29:
			kkaccept = 2;
			kkch = *(KKMARKER = ++KKCURSOR);
			if (kkch <= 0x00) goto kk28;
			goto kk102;
kk30:
			kkch = *++KKCURSOR;
			if (kkch <= '^') {
				if (kkch <= '@') goto kk28;
				if (kkch <= 'Z') goto kk99;
				goto kk28;
			} else {
				if (kkch == '`') goto kk28;
				if (kkch <= 'z') goto kk99;
				goto kk28;
			}
kk31:
			kkch = *++KKCURSOR;
			goto kk100;
kk32:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '+') goto kk97;
			if (kkch == '=') goto kk95;
/* #line 451 "scanner.re" */
			{
			token->opcode = PHVOLT_T_ADD;
			return 0;
		}
/* #line 585 "scanner.c" */
kk34:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '=') goto kk93;
/* #line 461 "scanner.re" */
			{
			token->opcode = PHVOLT_T_MUL;
			return 0;
		}
/* #line 594 "scanner.c" */
kk36:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '=') goto kk91;
/* #line 466 "scanner.re" */
			{
			token->opcode = PHVOLT_T_DIV;
			return 0;
		}
/* #line 603 "scanner.c" */
kk38:
			++KKCURSOR;
/* #line 486 "scanner.re" */
			{
			token->opcode = PHVOLT_T_CONCAT;
			return 0;
		}
/* #line 611 "scanner.c" */
kk40:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '.') goto kk89;
/* #line 496 "scanner.re" */
			{
			token->opcode = PHVOLT_T_DOT;
			return 0;
		}
/* #line 620 "scanner.c" */
kk42:
			++KKCURSOR;
/* #line 501 "scanner.re" */
			{
			token->opcode = PHVOLT_T_COMMA;
			return 0;
		}
/* #line 628 "scanner.c" */
kk44:
			++KKCURSOR;
/* #line 506 "scanner.re" */
			{
			token->opcode = PHVOLT_T_PARENTHESES_OPEN;
			return 0;
		}
/* #line 636 "scanner.c" */
kk46:
			++KKCURSOR;
/* #line 511 "scanner.re" */
			{
			token->opcode = PHVOLT_T_PARENTHESES_CLOSE;
			return 0;
		}
/* #line 644 "scanner.c" */
kk48:
			++KKCURSOR;
/* #line 516 "scanner.re" */
			{
			token->opcode = PHVOLT_T_SBRACKET_OPEN;
			return 0;
		}
/* #line 652 "scanner.c" */
kk50:
			++KKCURSOR;
/* #line 521 "scanner.re" */
			{
			token->opcode = PHVOLT_T_SBRACKET_CLOSE;
			return 0;
		}
/* #line 660 "scanner.c" */
kk52:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) <= '<') goto kk53;
			if (kkch <= '=') goto kk87;
			if (kkch <= '>') goto kk85;
kk53:
/* #line 601 "scanner.re" */
			{
			token->opcode = PHVOLT_T_LESS;
			return 0;
		}
/* #line 672 "scanner.c" */
kk54:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '=') goto kk81;
/* #line 541 "scanner.re" */
			{
			token->opcode = PHVOLT_T_ASSIGN;
			return 0;
		}
/* #line 681 "scanner.c" */
kk56:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '=') goto kk79;
/* #line 606 "scanner.re" */
			{
			token->opcode = PHVOLT_T_GREATER;
			return 0;
		}
/* #line 690 "scanner.c" */
kk58:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '=') goto kk75;
/* #line 596 "scanner.re" */
			{
			token->opcode = PHVOLT_T_NOT;
			return 0;
		}
/* #line 699 "scanner.c" */
kk60:
			++KKCURSOR;
/* #line 611 "scanner.re" */
			{
			token->opcode = PHVOLT_T_PIPE;
			return 0;
		}
/* #line 707 "scanner.c" */
kk62:
			++KKCURSOR;
/* #line 616 "scanner.re" */
			{
			token->opcode = PHVOLT_T_COLON;
			return 0;
		}
/* #line 715 "scanner.c" */
kk64:
			++KKCURSOR;
/* #line 621 "scanner.re" */
			{
			token->opcode = PHVOLT_T_QUESTION;
			return 0;
		}
/* #line 723 "scanner.c" */
kk66:
			++KKCURSOR;
			kkch = *KKCURSOR;
			goto kk74;
kk67:
/* #line 626 "scanner.re" */
			{
			token->opcode = PHVOLT_T_IGNORE;
			return 0;
		}
/* #line 734 "scanner.c" */
kk68:
			++KKCURSOR;
/* #line 631 "scanner.re" */
			{
			s->active_line++;
			token->opcode = PHVOLT_T_IGNORE;
			return 0;
		}
/* #line 743 "scanner.c" */
kk70:
			++KKCURSOR;
/* #line 637 "scanner.re" */
			{
			status = PHVOLT_SCANNER_RETCODE_EOF;
			break;
		}
/* #line 751 "scanner.c" */
kk72:
			kkch = *++KKCURSOR;
			goto kk28;
kk73:
			++KKCURSOR;
			kkch = *KKCURSOR;
kk74:
			if (kkbm[0+kkch] & 8) {
				goto kk73;
			}
			goto kk67;
kk75:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '=') goto kk77;
/* #line 576 "scanner.re" */
			{
			token->opcode = PHVOLT_T_NOTEQUALS;
			return 0;
		}
/* #line 771 "scanner.c" */
kk77:
			++KKCURSOR;
/* #line 591 "scanner.re" */
			{
			token->opcode = PHVOLT_T_NOTIDENTICAL;
			return 0;
		}
/* #line 779 "scanner.c" */
kk79:
			++KKCURSOR;
/* #line 566 "scanner.re" */
			{
			token->opcode = PHVOLT_T_GREATEREQUAL;
			return 0;
		}
/* #line 787 "scanner.c" */
kk81:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '=') goto kk83;
/* #line 571 "scanner.re" */
			{
			token->opcode = PHVOLT_T_EQUALS;
			return 0;
		}
/* #line 796 "scanner.c" */
kk83:
			++KKCURSOR;
/* #line 586 "scanner.re" */
			{
			token->opcode = PHVOLT_T_IDENTICAL;
			return 0;
		}
/* #line 804 "scanner.c" */
kk85:
			++KKCURSOR;
/* #line 581 "scanner.re" */
			{
			token->opcode = PHVOLT_T_NOTEQUALS;
			return 0;
		}
/* #line 812 "scanner.c" */
kk87:
			++KKCURSOR;
/* #line 536 "scanner.re" */
			{
			token->opcode = PHVOLT_T_LESSEQUAL;
			return 0;
		}
/* #line 820 "scanner.c" */
kk89:
			++KKCURSOR;
/* #line 491 "scanner.re" */
			{
			token->opcode = PHVOLT_T_RANGE;
			return 0;
		}
/* #line 828 "scanner.c" */
kk91:
			++KKCURSOR;
/* #line 561 "scanner.re" */
			{
			token->opcode = PHVOLT_T_DIV_ASSIGN;
			return 0;
		}
/* #line 836 "scanner.c" */
kk93:
			++KKCURSOR;
/* #line 556 "scanner.re" */
			{
			token->opcode = PHVOLT_T_MUL_ASSIGN;
			return 0;
		}
/* #line 844 "scanner.c" */
kk95:
			++KKCURSOR;
/* #line 546 "scanner.re" */
			{
			token->opcode = PHVOLT_T_ADD_ASSIGN;
			return 0;
		}
/* #line 852 "scanner.c" */
kk97:
			++KKCURSOR;
/* #line 476 "scanner.re" */
			{
			token->opcode = PHVOLT_T_INCR;
			return 0;
		}
/* #line 860 "scanner.c" */
kk99:
			++KKCURSOR;
			kkch = *KKCURSOR;
kk100:
			if (kkbm[0+kkch] & 16) {
				goto kk99;
			}
			goto kk5;
kk101:
			++KKCURSOR;
			kkch = *KKCURSOR;
kk102:
			if (kkbm[0+kkch] & 32) {
				goto kk101;
			}
			if (kkch <= 0x00) goto kk103;
			if (kkch <= '[') goto kk105;
			goto kk104;
kk103:
			KKCURSOR = KKMARKER;
			if (kkaccept <= 1) {
				if (kkaccept <= 0) {
					goto kk3;
				} else {
					goto kk24;
				}
			} else {
				goto kk28;
			}
kk104:
			++KKCURSOR;
			kkch = *KKCURSOR;
			if (kkch == '\n') goto kk103;
			goto kk101;
kk105:
			++KKCURSOR;
/* #line 434 "scanner.re" */
			{
			token->opcode = PHVOLT_T_STRING;
			token->value = estrndup(q, KKCURSOR - q - 1);
			token->len = KKCURSOR - q - 1;
			q = KKCURSOR;
			return 0;
		}
/* #line 905 "scanner.c" */
kk107:
			++KKCURSOR;
			kkch = *KKCURSOR;
kk108:
			if (kkbm[0+kkch] & 64) {
				goto kk107;
			}
			if (kkch <= 0x00) goto kk103;
			if (kkch <= '[') goto kk105;
			++KKCURSOR;
			kkch = *KKCURSOR;
			if (kkch == '\n') goto kk103;
			goto kk107;
kk110:
			++KKCURSOR;
/* #line 413 "scanner.re" */
			{
			s->mode = PHVOLT_MODE_RAW;
			token->opcode = PHVOLT_T_CLOSE_EDELIMITER;
			return 0;
		}
/* #line 927 "scanner.c" */
kk112:
			++KKCURSOR;
/* #line 551 "scanner.re" */
			{
			token->opcode = PHVOLT_T_SUB_ASSIGN;
			return 0;
		}
/* #line 935 "scanner.c" */
kk114:
			++KKCURSOR;
/* #line 481 "scanner.re" */
			{
			token->opcode = PHVOLT_T_DECR;
			return 0;
		}
/* #line 943 "scanner.c" */
kk116:
			kkch = *++KKCURSOR;
			if (kkch == '}') goto kk120;
			goto kk103;
kk117:
			kkch = *++KKCURSOR;
			if (kkch != '}') goto kk103;
			++KKCURSOR;
/* #line 399 "scanner.re" */
			{
			s->mode = PHVOLT_MODE_RAW;
			s->whitespace_control = 1;
			token->opcode = PHVOLT_T_CLOSE_DELIMITER;
			return 0;
		}
/* #line 959 "scanner.c" */
kk120:
			++KKCURSOR;
/* #line 426 "scanner.re" */
			{
			s->mode = PHVOLT_MODE_RAW;
			s->whitespace_control = 1;
			token->opcode = PHVOLT_T_CLOSE_EDELIMITER;
			return 0;
		}
/* #line 969 "scanner.c" */
kk122:
			++KKCURSOR;
/* #line 387 "scanner.re" */
			{
			s->mode = PHVOLT_MODE_RAW;
			token->opcode = PHVOLT_T_CLOSE_DELIMITER;
			return 0;
		}
/* #line 978 "scanner.c" */
kk124:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '-') goto kk130;
/* #line 406 "scanner.re" */
			{
			s->whitespace_control = 0;
			s->statement_position++;
			token->opcode = PHVOLT_T_OPEN_EDELIMITER;
			return 0;
		}
/* #line 989 "scanner.c" */
kk126:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) == '-') goto kk128;
/* #line 381 "scanner.re" */
			{
			s->whitespace_control = 0;
			token->opcode = PHVOLT_T_OPEN_DELIMITER;
			return 0;
		}
/* #line 999 "scanner.c" */
kk128:
			++KKCURSOR;
/* #line 393 "scanner.re" */
			{
			s->whitespace_control = 0;
			token->opcode = PHVOLT_T_OPEN_DELIMITER;
			return 0;
		}
/* #line 1008 "scanner.c" */
kk130:
			++KKCURSOR;
/* #line 419 "scanner.re" */
			{
			s->whitespace_control = 0;
			s->statement_position++;
			token->opcode = PHVOLT_T_OPEN_EDELIMITER;
			return 0;
		}
/* #line 1018 "scanner.c" */
kk132:
			kkch = *++KKCURSOR;
			if (kkch == 'F') goto kk135;
			if (kkch == 'f') goto kk135;
			goto kk100;
kk133:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 351 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_DO;
			return 0;
		}
/* #line 1035 "scanner.c" */
kk135:
			kkch = *++KKCURSOR;
			if (kkch == 'I') goto kk136;
			if (kkch != 'i') goto kk100;
kk136:
			kkch = *++KKCURSOR;
			if (kkch == 'N') goto kk137;
			if (kkch != 'n') goto kk100;
kk137:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk138;
			if (kkch != 'e') goto kk100;
kk138:
			kkch = *++KKCURSOR;
			if (kkch == 'D') goto kk139;
			if (kkch != 'd') goto kk100;
kk139:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 328 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_DEFINED;
			return 0;
		}
/* #line 1063 "scanner.c" */
kk141:
			kkch = *++KKCURSOR;
			if (kkch == 'T') goto kk142;
			if (kkch != 't') goto kk100;
kk142:
			kkch = *++KKCURSOR;
			if (kkch == 'U') goto kk143;
			if (kkch != 'u') goto kk100;
kk143:
			kkch = *++KKCURSOR;
			if (kkch == 'R') goto kk144;
			if (kkch != 'r') goto kk100;
kk144:
			kkch = *++KKCURSOR;
			if (kkch == 'N') goto kk145;
			if (kkch != 'n') goto kk100;
kk145:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 305 "scanner.re" */
			{
			token->opcode = PHVOLT_T_RETURN;
			return 0;
		}
/* #line 1090 "scanner.c" */
kk147:
			kkch = *++KKCURSOR;
			if (kkch == 'T') goto kk148;
			if (kkch != 't') goto kk100;
kk148:
			kkch = *++KKCURSOR;
			if (kkch == 'H') goto kk149;
			if (kkch != 'h') goto kk100;
kk149:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 300 "scanner.re" */
			{
			token->opcode = PHVOLT_T_WITH;
			return 0;
		}
/* #line 1109 "scanner.c" */
kk151:
			kkch = *++KKCURSOR;
			if (kkch <= 'L') {
				if (kkch == 'C') goto kk161;
				if (kkch <= 'K') goto kk100;
				goto kk160;
			} else {
				if (kkch <= 'c') {
					if (kkch <= 'b') goto kk100;
					goto kk161;
				} else {
					if (kkch == 'l') goto kk160;
					goto kk100;
				}
			}
kk152:
			kkch = *++KKCURSOR;
			if (kkch == 'N') goto kk153;
			if (kkch != 'n') goto kk100;
kk153:
			kkch = *++KKCURSOR;
			if (kkch == 'T') goto kk154;
			if (kkch != 't') goto kk100;
kk154:
			kkch = *++KKCURSOR;
			if (kkch == 'I') goto kk155;
			if (kkch != 'i') goto kk100;
kk155:
			kkch = *++KKCURSOR;
			if (kkch == 'N') goto kk156;
			if (kkch != 'n') goto kk100;
kk156:
			kkch = *++KKCURSOR;
			if (kkch == 'U') goto kk157;
			if (kkch != 'u') goto kk100;
kk157:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk158;
			if (kkch != 'e') goto kk100;
kk158:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 369 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_CONTINUE;
			return 0;
		}
/* #line 1160 "scanner.c" */
kk160:
			kkch = *++KKCURSOR;
			if (kkch == 'L') goto kk165;
			if (kkch == 'l') goto kk165;
			goto kk100;
kk161:
			kkch = *++KKCURSOR;
			if (kkch == 'H') goto kk162;
			if (kkch != 'h') goto kk100;
kk162:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk163;
			if (kkch != 'e') goto kk100;
kk163:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 340 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_CACHE;
			return 0;
		}
/* #line 1185 "scanner.c" */
kk165:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 289 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_CALL;
			return 0;
		}
/* #line 1197 "scanner.c" */
kk167:
			kkch = *++KKCURSOR;
			if (kkch == 'C') goto kk168;
			if (kkch != 'c') goto kk100;
kk168:
			kkch = *++KKCURSOR;
			if (kkch == 'R') goto kk169;
			if (kkch != 'r') goto kk100;
kk169:
			kkch = *++KKCURSOR;
			if (kkch == 'O') goto kk170;
			if (kkch != 'o') goto kk100;
kk170:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 278 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_MACRO;
			return 0;
		}
/* #line 1221 "scanner.c" */
kk172:
			kkch = *++KKCURSOR;
			if (kkch == 'O') goto kk178;
			if (kkch == 'o') goto kk178;
			goto kk100;
kk173:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk174;
			if (kkch != 'e') goto kk100;
kk174:
			kkch = *++KKCURSOR;
			if (kkch == 'A') goto kk175;
			if (kkch != 'a') goto kk100;
kk175:
			kkch = *++KKCURSOR;
			if (kkch == 'K') goto kk176;
			if (kkch != 'k') goto kk100;
kk176:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 375 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_BREAK;
			return 0;
		}
/* #line 1250 "scanner.c" */
kk178:
			kkch = *++KKCURSOR;
			if (kkch == 'C') goto kk179;
			if (kkch != 'c') goto kk100;
kk179:
			kkch = *++KKCURSOR;
			if (kkch == 'K') goto kk180;
			if (kkch != 'k') goto kk100;
kk180:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 267 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_BLOCK;
			return 0;
		}
/* #line 1270 "scanner.c" */
kk182:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 262 "scanner.re" */
			{
			token->opcode = PHVOLT_T_OR;
			return 0;
		}
/* #line 1281 "scanner.c" */
kk184:
			kkch = *++KKCURSOR;
			if (kkch == 'D') goto kk195;
			if (kkch == 'd') goto kk195;
			goto kk100;
kk185:
			kkch = *++KKCURSOR;
			if (kkch == 'T') goto kk186;
			if (kkch != 't') goto kk100;
kk186:
			kkch = *++KKCURSOR;
			if (kkch == 'O') goto kk187;
			if (kkch != 'o') goto kk100;
kk187:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk188;
			if (kkch != 'e') goto kk100;
kk188:
			kkch = *++KKCURSOR;
			if (kkch == 'S') goto kk189;
			if (kkch != 's') goto kk100;
kk189:
			kkch = *++KKCURSOR;
			if (kkch == 'C') goto kk190;
			if (kkch != 'c') goto kk100;
kk190:
			kkch = *++KKCURSOR;
			if (kkch == 'A') goto kk191;
			if (kkch != 'a') goto kk100;
kk191:
			kkch = *++KKCURSOR;
			if (kkch == 'P') goto kk192;
			if (kkch != 'p') goto kk100;
kk192:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk193;
			if (kkch != 'e') goto kk100;
kk193:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 357 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_AUTOESCAPE;
			return 0;
		}
/* #line 1330 "scanner.c" */
kk195:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 257 "scanner.re" */
			{
			token->opcode = PHVOLT_T_AND;
			return 0;
		}
/* #line 1341 "scanner.c" */
kk197:
			kkch = *++KKCURSOR;
			if (kkch == 'U') goto kk198;
			if (kkch != 'u') goto kk100;
kk198:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk199;
			if (kkch != 'e') goto kk100;
kk199:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 252 "scanner.re" */
			{
			token->opcode = PHVOLT_T_TRUE;
			return 0;
		}
/* #line 1360 "scanner.c" */
kk201:
			kkch = *++KKCURSOR;
			if (kkch == 'T') goto kk206;
			if (kkch == 't') goto kk206;
			goto kk100;
kk202:
			kkch = *++KKCURSOR;
			if (kkch == 'L') goto kk203;
			if (kkch != 'l') goto kk100;
kk203:
			kkch = *++KKCURSOR;
			if (kkch == 'L') goto kk204;
			if (kkch != 'l') goto kk100;
kk204:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 242 "scanner.re" */
			{
			token->opcode = PHVOLT_T_NULL;
			return 0;
		}
/* #line 1384 "scanner.c" */
kk206:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 322 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_NOT;
			return 0;
		}
/* #line 1396 "scanner.c" */
kk208:
			kkch = *++KKCURSOR;
			if (kkch == 'T') goto kk209;
			if (kkch != 't') goto kk100;
kk209:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 237 "scanner.re" */
			{
			token->opcode = PHVOLT_T_SET;
			return 0;
		}
/* #line 1411 "scanner.c" */
kk211:
			kkch = *++KKCURSOR;
			if (kkch == 'L') goto kk215;
			if (kkch == 'l') goto kk215;
			goto kk100;
kk212:
			kkch = *++KKCURSOR;
			if (kkch == 'R') goto kk213;
			if (kkch != 'r') goto kk100;
kk213:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 221 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_FOR;
			return 0;
		}
/* #line 1432 "scanner.c" */
kk215:
			kkch = *++KKCURSOR;
			if (kkch == 'S') goto kk216;
			if (kkch != 's') goto kk100;
kk216:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk217;
			if (kkch != 'e') goto kk100;
kk217:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 247 "scanner.re" */
			{
			token->opcode = PHVOLT_T_FALSE;
			return 0;
		}
/* #line 1451 "scanner.c" */
kk219:
			kkch = *++KKCURSOR;
			if (kkch == 'S') goto kk268;
			if (kkch == 's') goto kk268;
			goto kk100;
kk220:
			kkch = *++KKCURSOR;
			if (kkch == 'D') goto kk228;
			if (kkch == 'd') goto kk228;
			goto kk100;
kk221:
			kkch = *++KKCURSOR;
			if (kkch == 'T') goto kk222;
			if (kkch != 't') goto kk100;
kk222:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk223;
			if (kkch != 'e') goto kk100;
kk223:
			kkch = *++KKCURSOR;
			if (kkch == 'N') goto kk224;
			if (kkch != 'n') goto kk100;
kk224:
			kkch = *++KKCURSOR;
			if (kkch == 'D') goto kk225;
			if (kkch != 'd') goto kk100;
kk225:
			kkch = *++KKCURSOR;
			if (kkch == 'S') goto kk226;
			if (kkch != 's') goto kk100;
kk226:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 310 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_EXTENDS;
			return 0;
		}
/* #line 1493 "scanner.c" */
kk228:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'A':
			case 'a':	goto kk229;
			case 'B':
			case 'b':	goto kk230;
			case 'C':
			case 'c':	goto kk231;
			case 'F':
			case 'f':	goto kk232;
			case 'I':
			case 'i':	goto kk233;
			case 'M':
			case 'm':	goto kk234;
			default:	goto kk100;
			}
kk229:
			kkch = *++KKCURSOR;
			if (kkch == 'U') goto kk258;
			if (kkch == 'u') goto kk258;
			goto kk100;
kk230:
			kkch = *++KKCURSOR;
			if (kkch == 'L') goto kk253;
			if (kkch == 'l') goto kk253;
			goto kk100;
kk231:
			kkch = *++KKCURSOR;
			if (kkch == 'A') goto kk245;
			if (kkch == 'a') goto kk245;
			goto kk100;
kk232:
			kkch = *++KKCURSOR;
			if (kkch == 'O') goto kk242;
			if (kkch == 'o') goto kk242;
			goto kk100;
kk233:
			kkch = *++KKCURSOR;
			if (kkch == 'F') goto kk240;
			if (kkch == 'f') goto kk240;
			goto kk100;
kk234:
			kkch = *++KKCURSOR;
			if (kkch == 'A') goto kk235;
			if (kkch != 'a') goto kk100;
kk235:
			kkch = *++KKCURSOR;
			if (kkch == 'C') goto kk236;
			if (kkch != 'c') goto kk100;
kk236:
			kkch = *++KKCURSOR;
			if (kkch == 'R') goto kk237;
			if (kkch != 'r') goto kk100;
kk237:
			kkch = *++KKCURSOR;
			if (kkch == 'O') goto kk238;
			if (kkch != 'o') goto kk100;
kk238:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 284 "scanner.re" */
			{
			token->opcode = PHVOLT_T_ENDMACRO;
			return 0;
		}
/* #line 1562 "scanner.c" */
kk240:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 216 "scanner.re" */
			{
			token->opcode = PHVOLT_T_ENDIF;
			return 0;
		}
/* #line 1573 "scanner.c" */
kk242:
			kkch = *++KKCURSOR;
			if (kkch == 'R') goto kk243;
			if (kkch != 'r') goto kk100;
kk243:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 227 "scanner.re" */
			{
			token->opcode = PHVOLT_T_ENDFOR;
			return 0;
		}
/* #line 1588 "scanner.c" */
kk245:
			kkch = *++KKCURSOR;
			if (kkch <= 'L') {
				if (kkch == 'C') goto kk246;
				if (kkch <= 'K') goto kk100;
				goto kk247;
			} else {
				if (kkch <= 'c') {
					if (kkch <= 'b') goto kk100;
				} else {
					if (kkch == 'l') goto kk247;
					goto kk100;
				}
			}
kk246:
			kkch = *++KKCURSOR;
			if (kkch == 'H') goto kk250;
			if (kkch == 'h') goto kk250;
			goto kk100;
kk247:
			kkch = *++KKCURSOR;
			if (kkch == 'L') goto kk248;
			if (kkch != 'l') goto kk100;
kk248:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 295 "scanner.re" */
			{
			token->opcode = PHVOLT_T_ENDCALL;
			return 0;
		}
/* #line 1622 "scanner.c" */
kk250:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk251;
			if (kkch != 'e') goto kk100;
kk251:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 346 "scanner.re" */
			{
			token->opcode = PHVOLT_T_ENDCACHE;
			return 0;
		}
/* #line 1637 "scanner.c" */
kk253:
			kkch = *++KKCURSOR;
			if (kkch == 'O') goto kk254;
			if (kkch != 'o') goto kk100;
kk254:
			kkch = *++KKCURSOR;
			if (kkch == 'C') goto kk255;
			if (kkch != 'c') goto kk100;
kk255:
			kkch = *++KKCURSOR;
			if (kkch == 'K') goto kk256;
			if (kkch != 'k') goto kk100;
kk256:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 273 "scanner.re" */
			{
			token->opcode = PHVOLT_T_ENDBLOCK;
			return 0;
		}
/* #line 1660 "scanner.c" */
kk258:
			kkch = *++KKCURSOR;
			if (kkch == 'T') goto kk259;
			if (kkch != 't') goto kk100;
kk259:
			kkch = *++KKCURSOR;
			if (kkch == 'O') goto kk260;
			if (kkch != 'o') goto kk100;
kk260:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk261;
			if (kkch != 'e') goto kk100;
kk261:
			kkch = *++KKCURSOR;
			if (kkch == 'S') goto kk262;
			if (kkch != 's') goto kk100;
kk262:
			kkch = *++KKCURSOR;
			if (kkch == 'C') goto kk263;
			if (kkch != 'c') goto kk100;
kk263:
			kkch = *++KKCURSOR;
			if (kkch == 'A') goto kk264;
			if (kkch != 'a') goto kk100;
kk264:
			kkch = *++KKCURSOR;
			if (kkch == 'P') goto kk265;
			if (kkch != 'p') goto kk100;
kk265:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk266;
			if (kkch != 'e') goto kk100;
kk266:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 363 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_ENDAUTOESCAPE;
			return 0;
		}
/* #line 1704 "scanner.c" */
kk268:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk269;
			if (kkch != 'e') goto kk100;
kk269:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) <= '[') {
				if (kkch <= 'E') {
					if (kkch <= '/') goto kk270;
					if (kkch <= '9') goto kk99;
					if (kkch >= 'A') goto kk99;
				} else {
					if (kkch <= 'H') {
						if (kkch <= 'F') goto kk271;
						goto kk99;
					} else {
						if (kkch <= 'I') goto kk272;
						if (kkch <= 'Z') goto kk99;
					}
				}
			} else {
				if (kkch <= 'e') {
					if (kkch <= '^') {
						if (kkch <= '\\') goto kk99;
					} else {
						if (kkch != '`') goto kk99;
					}
				} else {
					if (kkch <= 'h') {
						if (kkch <= 'f') goto kk271;
						goto kk99;
					} else {
						if (kkch <= 'i') goto kk272;
						if (kkch <= 'z') goto kk99;
					}
				}
			}
kk270:
/* #line 201 "scanner.re" */
			{
			token->opcode = PHVOLT_T_ELSE;
			return 0;
		}
/* #line 1748 "scanner.c" */
kk271:
			kkch = *++KKCURSOR;
			if (kkch == 'O') goto kk275;
			if (kkch == 'o') goto kk275;
			goto kk100;
kk272:
			kkch = *++KKCURSOR;
			if (kkch == 'F') goto kk273;
			if (kkch != 'f') goto kk100;
kk273:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 211 "scanner.re" */
			{
			token->opcode = PHVOLT_T_ELSEIF;
			return 0;
		}
/* #line 1768 "scanner.c" */
kk275:
			kkch = *++KKCURSOR;
			if (kkch == 'R') goto kk276;
			if (kkch != 'r') goto kk100;
kk276:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 206 "scanner.re" */
			{
			token->opcode = PHVOLT_T_ELSEFOR;
			return 0;
		}
/* #line 1783 "scanner.c" */
kk278:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 195 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_IF;
			return 0;
		}
/* #line 1795 "scanner.c" */
kk280:
			++KKCURSOR;
			if ((kkch = *KKCURSOR) <= '[') {
				if (kkch <= '@') {
					if (kkch <= '/') goto kk281;
					if (kkch <= '9') goto kk99;
				} else {
					if (kkch == 'C') goto kk284;
					if (kkch <= 'Z') goto kk99;
				}
			} else {
				if (kkch <= '`') {
					if (kkch <= '\\') goto kk99;
					if (kkch == '_') goto kk99;
				} else {
					if (kkch == 'c') goto kk284;
					if (kkch <= 'z') goto kk99;
				}
			}
kk281:
/* #line 232 "scanner.re" */
			{
			token->opcode = PHVOLT_T_IN;
			return 0;
		}
/* #line 1821 "scanner.c" */
kk282:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 316 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_IS;
			return 0;
		}
/* #line 1833 "scanner.c" */
kk284:
			kkch = *++KKCURSOR;
			if (kkch == 'L') goto kk285;
			if (kkch != 'l') goto kk100;
kk285:
			kkch = *++KKCURSOR;
			if (kkch == 'U') goto kk286;
			if (kkch != 'u') goto kk100;
kk286:
			kkch = *++KKCURSOR;
			if (kkch == 'D') goto kk287;
			if (kkch != 'd') goto kk100;
kk287:
			kkch = *++KKCURSOR;
			if (kkch == 'E') goto kk288;
			if (kkch != 'e') goto kk100;
kk288:
			++KKCURSOR;
			if (kkbm[0+(kkch = *KKCURSOR)] & 16) {
				goto kk99;
			}
/* #line 334 "scanner.re" */
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_INCLUDE;
			return 0;
		}
/* #line 1861 "scanner.c" */
kk290:
			kkch = *++KKCURSOR;
			if (kkch <= '/') goto kk103;
			if (kkch <= '9') goto kk293;
			goto kk103;
kk291:
			kkaccept = 0;
			KKMARKER = ++KKCURSOR;
			kkch = *KKCURSOR;
kk292:
			if (kkbm[0+kkch] & 128) {
				goto kk291;
			}
			if (kkch == '.') goto kk290;
			goto kk3;
kk293:
			++KKCURSOR;
			kkch = *KKCURSOR;
			if (kkch <= '/') goto kk295;
			if (kkch <= '9') goto kk293;
kk295:
/* #line 187 "scanner.re" */
			{
			token->opcode = PHVOLT_T_DOUBLE;
			token->value = estrndup(start, KKCURSOR - start);
			token->len = KKCURSOR - start;
			q = KKCURSOR;
			return 0;
		}
/* #line 1891 "scanner.c" */
		}
/* #line 647 "scanner.re" */


		}
	}

	return status;
}
