/*
 *  Helper functions for VHDL syntax elements.
 *
 *  Copyright (C) 2008  Nick Gasson (nick@nickg.me.uk)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef INC_VHDL_HELPER_HH
#define INC_VHDL_HELPER_HH

#include <fstream>
#include <list>

template <class T>
void emit_children(std::ofstream &of,
                   const std::list<T*> &children,
                   int level, const char *delim="") 
{      
   // Don't indent if there are no children
   if (children.size() == 0)
      newline(of, level);
   else {
      typename std::list<T*>::const_iterator it;
      int sz = children.size();
      for (it = children.begin(); it != children.end(); ++it) {
         newline(of, indent(level));
         (*it)->emit(of, indent(level));
         if (--sz > 0)
            of << delim;
      }
      newline(of, level);
   }
}

template <class T>
void delete_children(std::list<T*> &children)
{
   typename std::list<T*>::iterator it;
   for (it = children.begin(); it != children.end(); ++it)
      delete *it;
   children.clear();
}

#endif
