/*******************************************************************************

  Copyright (c) 2010, 2013 LIFIA - Facultad de Informatica - Univ. Nacional de La Plata
  All rights reserved.

********************************************************************************

  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the author nor the names of its contributors may
      be used to endorse or promote products derived from this software
      without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

********************************************************************************

  La redistribución y el uso en las formas de código fuente y binario, con o sin
  modificaciones, están permitidos siempre que se cumplan las siguientes condiciones:
    * Las redistribuciones del código fuente deben conservar el aviso de copyright
      anterior, esta lista de condiciones y el siguiente descargo de responsabilidad.
    * Las redistribuciones en formato binario deben reproducir el aviso de copyright
      anterior, esta lista de condiciones y el siguiente descargo de responsabilidad
      en la documentación y/u otros materiales suministrados con la distribución.
    * Ni el nombre de los titulares de derechos de autor ni los nombres de sus
      colaboradores pueden usarse para apoyar o promocionar productos derivados de
      este software sin permiso previo y por escrito.

  ESTE SOFTWARE SE SUMINISTRA POR LIFIA "COMO ESTÁ" Y CUALQUIER GARANTÍA EXPRESA
  O IMPLÍCITA, INCLUYENDO, PERO NO LIMITADO A, LAS GARANTÍAS IMPLÍCITAS DE
  COMERCIALIZACIÓN Y APTITUD PARA UN PROPÓSITO DETERMINADO SON RECHAZADAS. EN
  NINGÚN CASO LIFIA SERÁ RESPONSABLE POR NINGÚN DAÑO DIRECTO, INDIRECTO, INCIDENTAL,
  ESPECIAL, EJEMPLAR O CONSECUENTE (INCLUYENDO, PERO NO LIMITADO A, LA ADQUISICIÓN
  DE BIENES O SERVICIOS; LA PÉRDIDA DE USO, DE DATOS O DE BENEFICIOS; O INTERRUPCIÓN
  DE LA ACTIVIDAD EMPRESARIAL) O POR CUALQUIER TEORÍA DE RESPONSABILIDAD, YA SEA
  POR CONTRATO, RESPONSABILIDAD ESTRICTA O AGRAVIO (INCLUYENDO NEGLIGENCIA O
  CUALQUIER OTRA CAUSA) QUE SURJA DE CUALQUIER MANERA DEL USO DE ESTE SOFTWARE,
  INCLUSO SI SE HA ADVERTIDO DE LA POSIBILIDAD DE TALES DAÑOS.

*******************************************************************************/

#include "volume.h"
#include <canvas/types.h>
#include <util/string.h>
#include <util/io/dispatcher.h>
#include <util/cfg/cfg.h>
#include <boost/bind.hpp>

namespace platform {

#define NORMALIZE_VOLUME( vol ) vol / ( 100 / MAX_VOLUME )

Volume::Volume()
	: MediaPlayerStep( "volume", "Going to test volume changes" )
{
	_volume = -1;
	_duration = -1;
	_step = -1;
}

Volume::~Volume()
{
}

void Volume::startImpl() {
	_duration = util::cfg::getValue<int>("tool.testplatform.volumeDuration");
	_step = util::cfg::getValue<int>("tool.testplatform.volumeStep");

	_volume = MIN_VOLUME;

	msg( util::format("\tVolume at %d%%", _volume) );
	addTimer( _duration * 1000, boost::bind(&Volume::onVolumeIncrease, this) );

	startVolumeImpl();
	volume( NORMALIZE_VOLUME(_volume) );

	play( "mp3" );
}

void Volume::stopImpl() {
	volume(10);
	stopVolumeImpl();
}

void Volume::onVolumeIncrease() {
	_volume += _step;
	if (_volume <= 100) {
		msg( util::format("\tVolume at %d%%", _volume) );
		volume( NORMALIZE_VOLUME(_volume) );
		addTimer( _duration * 1000, boost::bind(&Volume::onVolumeIncrease, this));
	} else {
		end();
	}
}

void Volume::startVolumeImpl() {
}

void Volume::stopVolumeImpl() {
}

}


