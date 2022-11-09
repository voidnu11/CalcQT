#ifndef SC_DATA_H
#define SC_DATA_H

#include <map>

namespace Calc_Alias {
const char ONE   = '1', TWO   = '2', THREE = '3';
const char FOUR  = '4', FIVE  = '5', SIX   = '6';
const char SEVEN = '7', EIGHT = '8', NINE  = '9';
const char ZERO  = '0', DOT   = '.', ADD   = 'p';
const char SUB   = 'm', MOD   = '%', POW   = '^';
const char E     = 'E', X     = 'x', BRO   = '(';
const char BRC   = ')', MUL   = '*', DIV   = '/';
const char LN    = 'l', LOG   = 'L', COS   = 'c';
const char SIN   = 's', TAN   = 't', ACOS  = 'C';
const char ASIN  = 'S', ATAN  = 'T', SQRT  = 'Q';
const char NEG   = '-', POS   = '+', EULER = 'e';
const char PI    = 'i';
}

namespace Calc_OperatorMask {
const int BRO  = 0;
const int BRC  = 0;
const int ADD  = 1;
const int SUB  = 1;
const int DIV  = 2;
const int MUL  = 2;
const int MOD  = 2;
const int POW  = 3;
const int SIN  = 4;
const int COS  = 4;
const int TAN  = 4;
const int ASIN = 4;
const int ACOS = 4;
const int ATAN = 4;
const int LN   = 4;
const int LOG  = 4;
const int SQRT = 4;

const std::map<char, int> map = {
    { Calc_Alias::COS,   COS   },
    { Calc_Alias::ACOS,  ACOS  },
    { Calc_Alias::SIN,   SIN   },
    { Calc_Alias::ASIN,  ASIN  },
    { Calc_Alias::TAN,   TAN   },
    { Calc_Alias::ATAN,  ATAN  },
    { Calc_Alias::LN,    LN    },
    { Calc_Alias::LOG,   LOG   },
    { Calc_Alias::SQRT,  SQRT  },
    { Calc_Alias::ADD,   ADD   },
    { Calc_Alias::SUB,   SUB   },
    { Calc_Alias::MUL,   MUL   },
    { Calc_Alias::DIV,   DIV   },
    { Calc_Alias::BRC,   BRC   },
    { Calc_Alias::POW,   POW   },
    { Calc_Alias::MOD,   MOD   },
    { Calc_Alias::BRO,   BRO   },
    { Calc_Alias::POS,   ADD   },
    { Calc_Alias::NEG,   SUB   },
};
}

namespace Calc_DText {
const std::string E     = "E",    BRO   = "(";
const std::string DOT   = ".",    ZERO  = "0";
const std::string ONE   = "1",    TWO   = "2";
const std::string THREE = "3",    FOUR  = "4";
const std::string FIVE  = "5",    SIX   = "6";
const std::string SEVEN = "7",    EIGHT = "8";
const std::string NINE  = "9",    BRC   = ")";
const std::string EULER = "e",    X     = "x";
const std::string POW   = "^",    MOD   = "%";
const std::string ADD   = "+",    SUB   = "-";
const std::string MUL   = "×",    DIV   = "÷";
const std::string LOG   = "log(", LN    = "ln(";
const std::string COS   = "cos(", ACOS  = "acos(";
const std::string SIN   = "sin(", ASIN  = "asin(";
const std::string TAN   = "tan(", ATAN  = "atan(";
const std::string PI    = "π",    SQRT  = "sqrt(";

const std::map<char, std::string> map = {
    { Calc_Alias::X,     X     },
    { Calc_Alias::E,     E     },
    { Calc_Alias::COS,   COS   },
    { Calc_Alias::ACOS,  ACOS  },
    { Calc_Alias::SIN,   SIN   },
    { Calc_Alias::ASIN,  ASIN  },
    { Calc_Alias::TAN,   TAN   },
    { Calc_Alias::ATAN,  ATAN  },
    { Calc_Alias::LN,    LN    },
    { Calc_Alias::LOG,   LOG   },
    { Calc_Alias::SQRT,  SQRT  },
    { Calc_Alias::ADD,   ADD   },
    { Calc_Alias::SUB,   SUB   },
    { Calc_Alias::MUL,   MUL   },
    { Calc_Alias::DIV,   DIV   },
    { Calc_Alias::PI,    PI    },
    { Calc_Alias::DOT,   DOT   },
    { Calc_Alias::ZERO,  ZERO  },
    { Calc_Alias::ONE,   ONE   },
    { Calc_Alias::TWO,   TWO   },
    { Calc_Alias::THREE, THREE },
    { Calc_Alias::FOUR,  FOUR  },
    { Calc_Alias::FIVE,  FIVE  },
    { Calc_Alias::SIX,   SIX   },
    { Calc_Alias::SEVEN, SEVEN },
    { Calc_Alias::EIGHT, EIGHT },
    { Calc_Alias::NINE,  NINE  },
    { Calc_Alias::BRC,   BRC   },
    { Calc_Alias::EULER, EULER },
    { Calc_Alias::POW,   POW   },
    { Calc_Alias::MOD,   MOD   },
    { Calc_Alias::BRO,   BRO   },
    { Calc_Alias::POS,   ADD   },
    { Calc_Alias::NEG,   SUB   },
};
}

namespace Calc_AllowedString {
const std::string CASE_1  = "0123456789E";
const std::string CASE_2  = "0123456789.E^%/*mp)";
const std::string CASE_3  = "^%/*mp)";
const std::string CASE_4  = "0123456789.iexQLCSTlcst+-(mp";
const std::string CASE_5  = "0123456789.iexQLCSTlcst(";
const std::string HANDLED = "^%/*+-(QLCSTlcst.)";
const std::string OPERATORS = "^%/*+-(QLCSTlcstmp";

const std::map<char, std::string> map = {
    { Calc_Alias::DOT,   CASE_1 },
    { Calc_Alias::ZERO,  CASE_2 },
    { Calc_Alias::ONE,   CASE_2 },
    { Calc_Alias::TWO,   CASE_2 },
    { Calc_Alias::THREE, CASE_2 },
    { Calc_Alias::FOUR,  CASE_2 },
    { Calc_Alias::FIVE,  CASE_2 },
    { Calc_Alias::SIX,   CASE_2 },
    { Calc_Alias::SEVEN, CASE_2 },
    { Calc_Alias::EIGHT, CASE_2 },
    { Calc_Alias::NINE,  CASE_2 },
    { Calc_Alias::E,     CASE_2 },
    { Calc_Alias::BRC,   CASE_3 },
    { Calc_Alias::EULER, CASE_3 },
    { Calc_Alias::PI,    CASE_3 },
    { Calc_Alias::X,     CASE_3 },
    { Calc_Alias::POW,   CASE_4 },
    { Calc_Alias::MOD,   CASE_4 },
    { Calc_Alias::MUL,   CASE_4 },
    { Calc_Alias::DIV,   CASE_4 },
    { Calc_Alias::ADD,   CASE_4 },
    { Calc_Alias::SUB,   CASE_4 },
    { Calc_Alias::COS,   CASE_4 },
    { Calc_Alias::ACOS,  CASE_4 },
    { Calc_Alias::SIN,   CASE_4 },
    { Calc_Alias::ASIN,  CASE_4 },
    { Calc_Alias::TAN,   CASE_4 },
    { Calc_Alias::ATAN,  CASE_4 },
    { Calc_Alias::LN,    CASE_4 },
    { Calc_Alias::LOG,   CASE_4 },
    { Calc_Alias::SQRT,  CASE_4 },
    { Calc_Alias::BRO,   CASE_4 },
    { Calc_Alias::POS,   CASE_5 },
    { Calc_Alias::NEG,   CASE_5 },
};
}

#endif // SC_DATA_H
