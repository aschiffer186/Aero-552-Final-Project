#include "lexer.hh"

namespace lexer
{
    token_t::token_t(index_t line, index_t start_col, index_t end_col, token_type type, const std::string& val)
        : _M_line(line), _M_start_col(start_col), _M_end_col(end_col), _M_type(type), _M_val(val)
    {

    }

    lexer::lexer(const std::string& text)
        : _M_pos(0), _M_line(0), _M_col(0), _M_text(text)
    {

    }

    std::vector<token_t> lexer::tokenize()
    {
        std::vector<token_t> tokens;
        token_t tok;
        do
        {
            tok = next_token();
            tokens.push_back(tok);
        } while(_M_pos < _M_text.length());
        tokens.push_back(make_token(token_type::tl_EOF,"$"));
        return tokens;
    }

    token_t lexer::next_token() {
     std::string value = "";
     tl0:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl9;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl8;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl7;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl6;
             }
         else if(c == '-')
             {
                  value += c;
                  advance();
                  goto tl4;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl13;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl12;
             }
         else if(c == '\\')
             {
                  value += c;
                  advance();
                  goto tl15;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl5;
             }
         else if(c == '%')
             {
                  value += c;
                  advance();
                  goto tl1;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl14;
             }
         else if(c == '+')
             {
                  value += c;
                  advance();
                  goto tl3;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl11;
             }
         else if(c == '*')
             {
                  value += c;
                  advance();
                  goto tl2;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl10;
             }
           else
                   return make_token(token_type::tl_ERROR , value);
     }
     tl1:
     {
          char c = next_character();
                  return make_token(token_type::tl_modulo, value);
     }
     tl2:
     {
          char c = next_character();
                  return make_token(token_type::tl_start, value);
     }
     tl3:
     {
          char c = next_character();
                  return make_token(token_type::tl_plus, value);
     }
     tl4:
     {
          char c = next_character();
                  return make_token(token_type::tl_minus, value);
     }
     tl5:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl6:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl7:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl8:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl9:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl10:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl11:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl12:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl13:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl14:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl15:
     {
          char c = next_character();
                  return make_token(token_type::tl_slash, value);
     }
     tl16:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl17:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl18:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl19:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl20:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl21:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl22:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl23:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl24:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     tl25:
     {
          char c = next_character();
         if(c == '4')
             {
                  value += c;
                  advance();
                  goto tl20;
             }
         else if(c == '3')
             {
                  value += c;
                  advance();
                  goto tl19;
             }
         else if(c == '2')
             {
                  value += c;
                  advance();
                  goto tl18;
             }
         else if(c == '0')
             {
                  value += c;
                  advance();
                  goto tl16;
             }
         else if(c == '1')
             {
                  value += c;
                  advance();
                  goto tl17;
             }
         else if(c == '8')
             {
                  value += c;
                  advance();
                  goto tl24;
             }
         else if(c == '9')
             {
                  value += c;
                  advance();
                  goto tl25;
             }
         else if(c == '7')
             {
                  value += c;
                  advance();
                  goto tl23;
             }
         else if(c == '6')
             {
                  value += c;
                  advance();
                  goto tl22;
             }
         else if(c == '5')
             {
                  value += c;
                  advance();
                  goto tl21;
             }
            else
                  return make_token(token_type::tl_int, value);
     }
     return make_token(token_type::tl_ERROR, value);}

    void lexer::advance()
    {
        if (_M_pos >= _M_text.length())
            return;
        do 
        {
            ++_M_pos;
            if (_M_text[_M_pos] == '\n')
            {
                ++_M_line; 
                _M_col = 0;
            }
            else 
            {
                ++_M_col;
            }
        } while(isspace(_M_text[_M_pos]));
    }

    char lexer::next_character() const
    {
        return (_M_pos >= _M_text.length()) ? 0 : _M_text[_M_pos];
    }

    char lexer::lookahead() const 
    {
        return (_M_pos + 1 >= _M_text.length()) ? 0 : _M_text[_M_pos + 1];
    }

    token_t lexer::make_token(token_type type, const std::string& value)
    {
        index_t start_col = _M_col - value.length();
        return token_t(_M_line, start_col, _M_col, type, value);
    }
} // namespace lexer
