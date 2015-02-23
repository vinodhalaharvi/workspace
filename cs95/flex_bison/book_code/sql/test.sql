select
	log.resource_id,
	res.name,
	log.detail,
	plat.fqdn
from
	EAM_EVENT_LOG log,
	EAM_RESOURCE res,
	EAM_SERVICE service,
	EAM_SERVER serv,
	EAM_PLATFORM plat
where
	log.id >= 6661448 and
	log.resource_id = res.id AND
	res.id = service.resource_id AND
	service.server_id = serv.id and
	serv.platform_id = plat.id 
