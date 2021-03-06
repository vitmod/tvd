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

  La redistribuci�n y el uso en las formas de c�digo fuente y binario, con o sin
  modificaciones, est�n permitidos siempre que se cumplan las siguientes condiciones:
	* Las redistribuciones del c�digo fuente deben conservar el aviso de copyright
	  anterior, esta lista de condiciones y el siguiente descargo de responsabilidad.
	* Las redistribuciones en formato binario deben reproducir el aviso de copyright
	  anterior, esta lista de condiciones y el siguiente descargo de responsabilidad
	  en la documentaci�n y/u otros materiales suministrados con la distribuci�n.
	* Ni el nombre de los titulares de derechos de autor ni los nombres de sus
	  colaboradores pueden usarse para apoyar o promocionar productos derivados de
	  este software sin permiso previo y por escrito.

  ESTE SOFTWARE SE SUMINISTRA POR LIFIA "COMO EST�" Y CUALQUIER GARANT�A EXPRESA
  O IMPL�CITA, INCLUYENDO, PERO NO LIMITADO A, LAS GARANT�AS IMPL�CITAS DE
  COMERCIALIZACI�N Y APTITUD PARA UN PROP�SITO DETERMINADO SON RECHAZADAS. EN
  NING�N CASO LIFIA SER� RESPONSABLE POR NING�N DA�O DIRECTO, INDIRECTO, INCIDENTAL,
  ESPECIAL, EJEMPLAR O CONSECUENTE (INCLUYENDO, PERO NO LIMITADO A, LA ADQUISICI�N
  DE BIENES O SERVICIOS; LA P�RDIDA DE USO, DE DATOS O DE BENEFICIOS; O INTERRUPCI�N
  DE LA ACTIVIDAD EMPRESARIAL) O POR CUALQUIER TEOR�A DE RESPONSABILIDAD, YA SEA
  POR CONTRATO, RESPONSABILIDAD ESTRICTA O AGRAVIO (INCLUYENDO NEGLIGENCIA O
  CUALQUIER OTRA CAUSA) QUE SURJA DE CUALQUIER MANERA DEL USO DE ESTE SOFTWARE,
  INCLUSO SI SE HA ADVERTIDO DE LA POSIBILIDAD DE TALES DA�OS.

*******************************************************************************/

#pragma once

#include <util/keydefs.h>
#include <vector>

namespace zapper {
	class Zapper;
}

namespace canvas {
namespace input {
	struct ButtonEventS;
	typedef struct ButtonEventS ButtonEvent;
}
}

namespace platform {

	struct ChannelInfo {
		const char *name;
		int id;
		int srvID;
		int remote;
		bool haveDownload;
	};

	class Step;
	typedef std::vector<platform::Step *> Steps;

	class Test;
	typedef std::vector<platform::Test *> Tests;

	namespace status {
		enum type { unexecuted, waiting, running, ended, succeeded, failed };
	}

	namespace command {
		enum type { nextStep, previousStep, nextTest, previousTest, repeat };
	}
}
