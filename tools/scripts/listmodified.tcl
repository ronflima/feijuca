#!/usr/bin/tclsh
#
# G.A. Library - A generic algorithms and data structures library
# Copyright (C) 2005 - Ronaldo Faria Lima
#
# This library is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation; either version 2.1 of the
# License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
# USA
#
# Small utility to list all modified files within the ga-lib source
# tree
# Author: Ronaldo Faria Lima <ronaldo@ronaldolima.eti.br>
# $Id: listmodified.tcl,v 1.1 2005-12-19 00:42:52 ron_lima Exp $

set cvs [open "|cvs status 2> /dev/null"]
set found 0

while {! [eof $cvs]} {
    gets $cvs line
    if { [string match "*Modified*" $line] || $found } {
        set found 1
        if { [string match "*Repository revision:*" $line] } {
            set found 0
            set line [split [lindex [split $line] 6] ,]
            puts [lindex $line 0]
        }
    }
}
close $cvs
