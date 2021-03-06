/*******************************************************************************

  Copyright (C) 2010, 2013 LIFIA - Facultad de Informatica - Univ. Nacional de La Plata

********************************************************************************

  This file is part of DTV-util implementation.

    DTV-util is free software: you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by the Free
  Software Foundation, either version 2 of the License.

    DTV-util is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
  A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>.

********************************************************************************

  Este archivo es parte de la implementación de DTV-util.

    DTV-util es Software Libre: Ud. puede redistribuirlo y/o modificarlo
  bajo los términos de la Licencia Pública General Reducida GNU como es publicada por la
  Free Software Foundation, según la versión 2 de la licencia.

    DTV-util se distribuye esperando que resulte de utilidad, pero SIN NINGUNA
  GARANTÍA; ni siquiera la garantía implícita de COMERCIALIZACIÓN o ADECUACIÓN
  PARA ALGÚN PROPÓSITO PARTICULAR. Para más detalles, revise la Licencia Pública
  General Reducida GNU.

    Ud. debería haber recibido una copia de la Licencia Pública General Reducida GNU
  junto a este programa. Si no, puede verla en <http://www.gnu.org/licenses/>.

*******************************************************************************/

#pragma once

#include "nodehandler.h"
#include "../documenthandlerimpl.h"
#include <string>

namespace util {
namespace xml {
namespace dom {
namespace xerces {

class NodeHandler;
class ErrorHandler;

class DocumentHandler : public DocumentHandlerImpl<NodeHandler> {
public:
	DocumentHandler();
	virtual ~DocumentHandler();

protected:
	virtual bool init();
	virtual void fin();

	// Document methods impl
	virtual Document loadXMLImpl( const std::string &xml );
	virtual Document loadXMLImpl( const Buffer *buf );
	virtual Document loadDocumentImpl( const std::string &file );
	virtual Document createDocumentImpl( const std::string &rootElement );
	virtual bool saveImpl( Document doc, const std::string &file );
	virtual bool saveImpl( Document doc, Buffer *buf );
	virtual bool closeImpl( Document doc );

	// Node methods impl
	virtual Node rootImpl( Document doc ) const;
	virtual Node createTextNodeImpl( Document doc, const std::string &text );
	virtual Node createElementImpl( Document doc, const std::string &tagname );

	// Aux
	Document doLoad( const xercesc::InputSource &source );

private:
	xercesc::XercesDOMParser *_domParser;
	ErrorHandler *_errHnd;
};

}
}
}
}
