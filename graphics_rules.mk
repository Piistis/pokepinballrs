GFX_JSONS := $(shell find graphics -type f -name '*.json')
GFX_RULES_SCRIPT := tools/scripts/generate_graphics_rules.sh
GFX_RULES_GEN := graphics_rules_generated.mk

$(GFX_RULES_GEN): $(GFX_JSONS) $(GFX_RULES_SCRIPT)
	bash $(GFX_RULES_SCRIPT) $(GFX_JSONS) > $@

-include $(GFX_RULES_GEN)

graphics/field_select/sprites.4bpp: graphics/field_select/sprites.png
	$(GFX) $< $@ -num_tiles 513

graphics/options/sprites.4bpp: graphics/options/sprites.png
	$(GFX) $< $@ -num_tiles 257

graphics/pokedex/text_glyphs.4bpp: graphics/pokedex/text_glyphs.png
	$(GFX) $< $@ -num_tiles 513

graphics/mon_portraits/%_portrait.gbapal: graphics/mon_portraits/%_portrait.png tools/scripts/generate_pokedex_assets.py tools/scripts/generate_encounters_assets.py
	python3 tools/scripts/generate_pokedex_assets.py --portrait-palette $< --output $@

graphics/mon_portraits/%_portrait.4bpp: graphics/mon_portraits/%_portrait.png
	$(GFX) $< $@ -mwidth 2 -mheight 2
