<?xml version="1.0" encoding="ISO-8859-1"?>
<ncl id="test_region_bottom_15" xmlns="http://www.ncl.org.br/NCL3.0/EDTVProfile">
	<head>
		<regionBase>
			<region id="reg1"  bottom="40invalidValue"/>
		</regionBase>
		<descriptorBase>
			<descriptor id="desc1" region="reg1" />
		</descriptorBase>
	</head>
	<body>
		<port id="port1" component="image1" />
		<media id="image1" src="../../../../images/blue.jpg" descriptor="desc1" />
	</body>
</ncl>
