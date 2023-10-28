.DEFAULT_GOAL := help

.PHONY: help # run always if requested (volatile resource)

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

install: ## Install npm dependencies for the api, admin, and frontend apps
	@echo "Installing Node dependencies"
	@npm install

install-dev: install ## Install dependencies and prepared development configuration
	@./node_modules/.bin/selenium-standalone install
	@cp -n ./config/development.js-dist ./config/development.js | true
