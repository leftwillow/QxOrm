/****************************************************************************
**
** http://www.qxorm.com/
** http://sourceforge.net/projects/qxorm/
** Original file by Lionel Marty
**
** This file is part of the QxOrm library
**
** This software is provided 'as-is', without any express or implied
** warranty. In no event will the authors be held liable for any
** damages arising from the use of this software.
**
** GNU Lesser General Public License Usage
** This file must be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file 'license.lgpl.txt' included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you have questions regarding the use of this file, please contact :
** contact@qxorm.com
**
****************************************************************************/

#if (QT_VERSION >= 0x040600)
#ifndef _QX_SERIALIZE_QSCOPEDPOINTER_H_
#define _QX_SERIALIZE_QSCOPEDPOINTER_H_

#ifdef _MSC_VER
#pragma once
#endif

#ifndef Q_MOC_RUN
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/nvp.hpp>
#endif

#include <QtCore/qscopedpointer.h>

namespace boost {
namespace serialization {

template <class Archive, typename T>
inline void save(Archive & ar, const QScopedPointer<T> & t, const unsigned int file_version)
{
   Q_UNUSED(file_version);
   const T * ptr = t.data();
   ar << boost::serialization::make_nvp("qt_scoped_ptr", ptr);
}

template <class Archive, typename T>
inline void load(Archive & ar, QScopedPointer<T> & t, const unsigned int file_version)
{
   Q_UNUSED(file_version);
   T * ptr = NULL;
   ar >> boost::serialization::make_nvp("qt_scoped_ptr", ptr);
   t.reset(ptr);
}

template <class Archive, typename T>
inline void serialize(Archive & ar, QScopedPointer<T> & t, const unsigned int file_version)
{
   boost::serialization::split_free(ar, t, file_version);
}

} // namespace boost
} // namespace serialization

#endif // _QX_SERIALIZE_QSCOPEDPOINTER_H_
#endif // (QT_VERSION >= 0x040600)
