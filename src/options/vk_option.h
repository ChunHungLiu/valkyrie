/* --------------------------------------------------------------------- 
 * Definition of class Option                                vk_option.h
 * ---------------------------------------------------------------------
 */

#ifndef __VK_OPTION_H
#define __VK_OPTION_H

#include <qstringlist.h>


/* helper functions ---------------------------------------------------- */
//RM: QString dirCheck( int* err_val, const char* fpath, bool ckwr=true );
//RM: QString binaryCheck( int* err_val, const char* fpath );
//RM: QString formatCheck( int* err_val, const char* argval );





/* class Option -------------------------------------------------------- */
class Option 
{
public:
  /* TODO: currently, these correspond to the values in vk_popt.h
   it's a 'orrible hack, must be tidied up at some point. */
  enum ArgType { 
    NOT_POPT=-1, ARG_NONE=0, ARG_STRING=1, ARG_UINT=2,  ARG_BOOL=3 
  };

	/* these are kept in here in order to avoid depending on the gui */
  enum WidgetType { 
    NONE=-1, CHECK=0, RADIO, LEDIT, COMBO, LISTBOX, SPINBOX
  };

  Option( int opt_key,       ArgType arg_type,  WidgetType w_type, 
          QString cfg_group, QChar short_flag,  QString long_flag, 
          QString flag_desc, QString poss_vals, QString default_val, 
          QString shelp,     QString lhelp,     const char* url );

  QString cfgKey()    { return longFlag; }
  QString cfgGroup()  { return configGroup; }
	QString defValue()  { return defaultValue; }
  QString url() const { return urlHelp; }

	QString fileCheck( int* err_val, const char* fpath, 
										 bool rd_perms, bool wr_perms );
	QString binaryCheck( int* err_val, const char* exe_name );
	QString dirCheck( int* err_val, const char* fpath,
										bool rd_perms, bool wr_perms );

	bool xmlFormatCheck( int* errval, QString fpath );
  bool isValidArg( int* err_val, const char* argval );
  bool isPowerOfTwo( int* err_val, const char* argval );

  void setPossibleValues( QStringList vals );
  void print();                /* for debugging */

public:
  bool        modified;

  ArgType     argType;         /* option type, eg. ARG_UINT   */
  WidgetType  widgType;        /* eg. OptWidget::LEDIT        */

  int key;                     /* eg. LEAK_CHK                */
  QString     configGroup;     /* eg. [valkyrie]              */
  QChar       shortFlag;       /* eg. --l                     */
  QString     longFlag;        /* eg. --leak-resolution       */
  QString     flagDescrip;     /* eg. <file>                  */
  QString     shortHelp;       /* txt for OptionsWindow       */
  QString     longHelp;        /* txt for help --> stdout     */
  QString     urlHelp;         /* context help url            */
  QString     defaultValue;    /* eg. [low]                   */
  QStringList possValues;      /* eg. low | med | high        */
};



#endif
