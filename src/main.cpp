/*******************************************************************************************
*
*   raylib-extras [ImGui] example - Simple Integration
*
*	This is a simple ImGui Integration
*	It is done using C++ but with C style code
*	It can be done in C as well if you use the C ImGui wrapper
*	https://github.com/cimgui/cimgui
*
*   Copyright (c) 2021 Jeffery Myers
*
********************************************************************************************/

#include "raylib.h"
#include "raymath.h"

#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "renderers/raylib/clay_renderer_raylib.c"

const int FONT_ID_BODY_16 = 0;

const Clay_Color COLOR_LIGHT = {224, 215, 210, 255};
const Clay_Color COLOR_RED =  {168, 66, 28, 255};
const Clay_Color COLOR_ORANGE =  {225, 138, 50, 255};

// Layout config is just a struct that can be declared statically, or inline
Clay_LayoutConfig sidebarItemLayout =  {
    .sizing = { .width = CLAY_SIZING_GROW(0), .height = CLAY_SIZING_FIXED(50) },
	.padding = CLAY_PADDING_ALL(16)
	
};

// Re-useable components are just normal functions
void SidebarItemComponent(Clay_String text) {
    CLAY(CLAY_LAYOUT(sidebarItemLayout), CLAY_RECTANGLE({ .color = COLOR_ORANGE })) {
		CLAY_TEXT(text, CLAY_TEXT_CONFIG({ .textColor = {255, 255, 255, 255}, .fontSize = 24 }));
	}
}

// An example function to begin the "root" of your layout tree
Clay_RenderCommandArray CreateLayout() {
    Clay_BeginLayout();

    // An example of laying out a UI with a fixed width sidebar and flexible width main content
    CLAY(CLAY_ID("OuterContainer"), CLAY_LAYOUT({ .sizing = {CLAY_SIZING_GROW(0), CLAY_SIZING_GROW(0)}, .padding = CLAY_PADDING_ALL(16), .childGap = 16 }), CLAY_RECTANGLE({ .color = {250,250,255,255} })) {
		CLAY(CLAY_ID("SideBar"),
            CLAY_LAYOUT({.sizing = { .width = CLAY_SIZING_FIXED(300), .height = CLAY_SIZING_GROW(0) }, .padding = CLAY_PADDING_ALL(16), .childGap = 16, .layoutDirection = CLAY_TOP_TO_BOTTOM }),
            CLAY_RECTANGLE({ .color = COLOR_LIGHT })
        ) {
            // Standard C code like loops etc work inside components
            for (int i = 0; i < 5; i++) {
                SidebarItemComponent(CLAY_STRING("Hello, world"));
            }
        }
        CLAY(CLAY_ID("MainContent"), CLAY_LAYOUT({ .sizing = { .width = CLAY_SIZING_GROW(0), .height = CLAY_SIZING_GROW(0) }}), CLAY_RECTANGLE({ .color = COLOR_LIGHT })) {
 			
		}
    }
	return Clay_EndLayout();
   
};

void HandleClayErrors(Clay_ErrorData errorData) {
    printf("%s", errorData.errorText.chars);
}

int main(int argc, char* argv[])
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1280;
	int screenHeight = 800;

	SetConfigFlags(FLAG_WINDOW_RESIZABLE|FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
	//InitWindow(screenWidth, screenHeight, "raylib-Extras [ImGui] example - simple ImGui Demo");
	Clay_Raylib_Initialize(1024, 768, "Introducing Clay Demo", FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT); // Extra parameters to this function are new since the video was published

	SetTargetFPS(144);

	uint64_t totalMemorySize = Clay_MinMemorySize();
		Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(totalMemorySize, (char *)malloc(totalMemorySize));
		Clay_Initialize(clayMemory, Clay_Dimensions {1024,768}, Clay_ErrorHandler { HandleClayErrors });

		Clay_SetMeasureTextFunction(Raylib_MeasureText, 0);

	Raylib_fonts[FONT_ID_BODY_16] = {
        .fontId = FONT_ID_BODY_16,
		.font = LoadFontEx ("Roboto-Regular.ttf", 48, 0, 400)
    };
    SetTextureFilter(Raylib_fonts[FONT_ID_BODY_16].font.texture, TEXTURE_FILTER_BILINEAR);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		Clay_SetLayoutDimensions({ (float)GetScreenWidth(), (float)GetScreenHeight() });

		Clay_RenderCommandArray renderCommands = CreateLayout();
		
		BeginDrawing();
		ClearBackground(DARKGRAY);

		Clay_Raylib_Render(renderCommands);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}
	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}