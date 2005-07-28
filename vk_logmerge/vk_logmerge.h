/* ---------------------------------------------------------------------
 * Definition of VKLogMerge                                vk_logmerge.h
 * ---------------------------------------------------------------------
 * This file is part of Valkyrie, a front-end for Valgrind
 * Copyright (c) 2000-2005, OpenWorks LLP <info@open-works.co.uk>
 * This program is released under the terms of the GNU GPL v.2
 * See the file LICENSE.GPL for the full license details.
 */

#ifndef __VK_LOGMERGE_OBJECT_H
#define __VK_LOGMERGE_OBJECT_H

#include "vglog.h"
#include "xml_parser.h"

/* class VKLogMerge ------------------------------------------------------ */
class VKLogMerge : public QObject
{
  Q_OBJECT
public:
  VKLogMerge( QObject * parent = 0, const char * name = 0 );
  ~VKLogMerge();

  bool mergeLogFiles( QString& log_list, QString& fname_out );

private:
  bool parseLog( XMLParser* xmlParser, VGLog* vgLog,
                 QXmlSimpleReader& reader, QString& log_fname );
  QString validateFile( QString& log_file );
};


#endif // #ifndef __VK_LOGMERGE_OBJECT_H
