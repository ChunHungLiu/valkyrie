/* ---------------------------------------------------------------------- 
 * Definition of ValkyrieOptionsPage              valkyrie_options_page.h
 * Subclass of OptionsPage to hold valkyrie-specific options | flags
 * ---------------------------------------------------------------------- 
 * This file is part of Valkyrie, a front-end for Valgrind
 * Copyright (c) 2000-2005, Donna Robinson <donna@valgrind.org>
 * This program is released under the terms of the GNU GPL v.2
 * See the file LICENSE.GPL for the full license details.
 */

#ifndef __VALKYRIE_OPTIONS_PAGE_H
#define __VALKYRIE_OPTIONS_PAGE_H

#include "options_page.h"


class ValkyrieOptionsPage : public OptionsPage
{
  Q_OBJECT
public:
  ValkyrieOptionsPage( QWidget* parent, VkObject* obj );
  bool applyOptions( int optId, bool undo=false );

private slots:
  void chooseFont();
  void fontClicked(bool);
  void checkEditor();
  void getBinary();
  void getVgExec();
  void getSuppDir();
};


#endif
