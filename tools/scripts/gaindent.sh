#!/bin/bash

# G.A. Library Developer support tools 

# Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved 

# Feel free to contact the author in <ronaldo@ronaldolima.eti.br>

# This file is part of G.A. Lib.

# G.A. Lib is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.

# G.A. Lib is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with G.A. Lib; if not, write to the Free Software Foundation,
# Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

#  System: G.A. Lib

#  Description: Indentation script for source code beautification
#  under GNU standards

# $Id: gaindent.sh,v 1.1 2005-12-19 00:42:19 ron_lima Exp $


# Command line checking
if [ $# -eq 0 ]
then
    echo "Usage: $0 <filename>"
fi

# Check for indent version
INDENT=""
INDENT_OPTS="-nbad -bap -nbc -bbo -bl -bli2 -bls -ncdb -nce -cp1 -cs -di2\
 -ndj -nfc1 -nfca -hnl -i2 -ip5 -lp -pcs -psl -nsc -nsob"

cmd=`indent --version 2> /dev/null | grep GNU`
if [ -z "$cmd" ]
then
    # Try to use gindent instead
    cmd=`gindent --version | grep GNU`
    if [ ! -z "$cmd" ]
    then
      INDENT="gindent"
    fi
else
  INDENT="indent"
fi

if [ -z "$INDENT" ]
then
    echo "No suitable indenting software was found."
    echo "Download GNU indent from www.gnu.org"
else
    echo "Using $INDENT to indent $1..."
    if [ ! -w $1 ]
    then
        echo "Could not open file $1 for reading/writting..."
    else
        # Makes the indentation
        $INDENT $INDENT_OPTS $1
        # Deletes all tabs from the file
        cat $1 | sed 's/^[	]/        /' > $1.tmp
        mv $1.tmp $1
    fi
fi
