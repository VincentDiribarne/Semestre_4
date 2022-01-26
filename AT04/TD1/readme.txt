Corriger le problème d'authentification ou de token pour un accès collectif (groupe td)
	Ajuter dans composer.json
	"config":{
        "github-oauth":{
            "github.com":"733d2713b4a34b0002a59902adc0ca6a78b7a2ff" <---- Token obtenu sur le site https://github.com/settings/tokens
        }
    },

Supprimer /bin et /vendor