/*******************************************************************************

  Copyright (C) 2010, 2013 LIFIA - Facultad de Informatica - Univ. Nacional de La Plata

********************************************************************************

  This file is part of DTV-zapper implementation.

    DTV-zapper is free software: you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by the Free
  Software Foundation, either version 2 of the License.

    DTV-zapper is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
  A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>.

********************************************************************************

  Este archivo es parte de la implementaci�n de DTV-zapper.

    DTV-zapper es Software Libre: Ud. puede redistribuirlo y/o modificarlo
  bajo los t�rminos de la Licencia P�blica General Reducida GNU como es publicada por la
  Free Software Foundation, seg�n la versi�n 2 de la licencia.

    DTV-zapper se distribuye esperando que resulte de utilidad, pero SIN NINGUNA
  GARANT�A; ni siquiera la garant�a impl�cita de COMERCIALIZACI�N o ADECUACI�N
  PARA ALG�N PROP�SITO PARTICULAR. Para m�s detalles, revise la Licencia P�blica
  General Reducida GNU.

    Ud. deber�a haber recibido una copia de la Licencia P�blica General Reducida GNU
  junto a este programa. Si no, puede verla en <http://www.gnu.org/licenses/>.

*******************************************************************************/

#include "time.h"
#include <mpegparser/time.h>
#include <util/task/dispatcher.h>

namespace pvr {
namespace dvb {

static void myTimeCallback( bool isValid, Time *time, util::task::Dispatcher *disp ) {
	disp->post( time, boost::bind(&Time::onTimeChanged,time,isValid) );
}

Time::Time( int offset, const std::string &countryCode, util::task::Dispatcher *disp )
	: pvr::Time( offset, countryCode ), _disp(disp)
{
	disp->registerTarget( this, "zapper::tstime" );
	_conn = tuner::time::clock.onTimeValidChanged().connect( boost::bind(&myTimeCallback,_1,this,disp) );
}

Time::~Time()
{
	_disp->unregisterTarget( this );
	_conn.disconnect();
}

//	Getters
bool Time::isValid() const {
	return tuner::time::clock.isValid();
}

void Time::get( bpt::ptime &value ) {
	tuner::time::clock.get( value );
	localTime( value );
}

void Time::onTimeChanged( bool isValid ) {
	notify( isValid );
}

}
}

