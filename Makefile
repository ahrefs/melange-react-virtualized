project_name = melange-react-virtualized

DUNE = opam exec -- dune

.DEFAULT_GOAL := help

.PHONY: help
help: ## Print this help message
	@echo "List of available make commands";
	@echo "";
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2}';
	@echo "";

.PHONY: create-switch
create-switch: ## Create opam switch
	opam switch create . 4.14.1 --no-install

.PHONY: init
init: create-switch install ## Configure everything to develop this repository in local

.PHONY: install
install: ## Install development dependencies
	opam update
	# pin reason-react and ppx as the latter is not available in opam yet
	opam pin add reason-react-ppx.dev -y git+https://github.com/reasonml/reason-react#52aa51b8a0e85788f6d775b409a5594c0022691f
	opam pin add reason-react.dev -y git+https://github.com/reasonml/reason-react#52aa51b8a0e85788f6d775b409a5594c0022691f
	opam install -y . --deps-only

.PHONY: build
build: ## Build the project
	$(DUNE) build @melange

.PHONY: build_verbose
build_verbose: ## Build the project
	$(DUNE) build --verbose @melange

.PHONY: clean
clean: ## Clean build artifacts and other generated files
	$(DUNE) clean

.PHONY: format
format: ## Format the codebase with ocamlformat
	$(DUNE) build @fmt --auto-promote

.PHONY: format-check
format-check: ## Checks if format is correct
	$(DUNE) build @fmt

.PHONY: watch
watch: ## Watch for the filesystem and rebuild on every change
	$(DUNE) build --watch @melange
