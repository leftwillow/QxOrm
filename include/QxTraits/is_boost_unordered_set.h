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

#ifndef _QX_IS_BOOST_UNORDERED_SET_H_
#define _QX_IS_BOOST_UNORDERED_SET_H_

#ifdef _MSC_VER
#pragma once
#endif

/*!
 * \file is_boost_unordered_set.h
 * \author Lionel Marty
 * \ingroup QxTraits
 * \brief qx::trait::is_boost_unordered_set<T>::value : return true if T is a boost::unordered_set<> or boost::unordered_multiset<> container, otherwise return false
 */

#ifndef Q_MOC_RUN
#include <boost/unordered_set.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/logical.hpp>
#endif

namespace qx {
namespace trait {

/*!
 * \ingroup QxTraits
 * \brief qx::trait::is_boost_unordered_set<T>::value : return true if T is a boost::unordered_set<> or boost::unordered_multiset<> container, otherwise return false
 */
template <typename T>
class is_boost_unordered_set
{

private:

   template <typename V> static char isContainer(const boost::unordered_set<V> &);
   template <typename V> static char isContainer(const boost::unordered_multiset<V> &);
   static int isContainer(...);
   static T t;

public:

   enum { value = (sizeof(qx::trait::is_boost_unordered_set<T>::isContainer(t)) == sizeof(char)) };

   typedef typename boost::mpl::if_c<qx::trait::is_boost_unordered_set<T>::value,
                                     boost::mpl::true_,
                                     boost::mpl::false_>::type type;

};

} // namespace trait
} // namespace qx

#endif // _QX_IS_BOOST_UNORDERED_SET_H_
