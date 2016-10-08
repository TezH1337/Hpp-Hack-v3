#include "IniRead.h"

#pragma warning(disable: 4800)

namespace Files
{
	void IniRead::ESP ( )
	{
		std::string esp = g_File->szDirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( enable, esp, mESP, ESP_ENABLE );	
		INIREAD_INT ( player, esp, mESP, ESP_PLAYER );
		INIREAD_INT ( player_visible_check, esp, mESP, ESP_VISIBLE_CHECK );
		INIREAD_INT ( player_box, esp, mESP, ESP_PLAYER_BOX );
		INIREAD_INT ( player_box_style, esp, mESP, ESP_PLAYER_BOX_STYLE );

		INIREAD ( t_vis_color_string, esp, mESP, ESP_PLAYER_BOX_T_VIS );
		INIREAD ( t_hide_color_string, esp, mESP, ESP_PLAYER_BOX_T_HIDE );
		INIREAD ( ct_vis_color_string, esp, mESP, ESP_PLAYER_BOX_CT_VIS );
		INIREAD ( ct_hide_color_string, esp, mESP, ESP_PLAYER_BOX_CT_HIDE );

		g_Util.Parse ( 4, g_IniRead->esp->t_vis_color_string, g_IniRead->esp->t_vis_color );
		g_Util.Parse ( 4, g_IniRead->esp->t_hide_color_string, g_IniRead->esp->t_hide_color );
		g_Util.Parse ( 4, g_IniRead->esp->ct_vis_color_string, g_IniRead->esp->ct_vis_color );
		g_Util.Parse ( 4, g_IniRead->esp->ct_hide_color_string, g_IniRead->esp->ct_hide_color );
	}

	void IniRead::Main ( )
	{
		std::string main = g_File->szDirFile ( MAIN_PATH ).c_str ( );

		INIREAD_STRING ( language, main, MAIN, MAIN_LANGUAGE );

		INIREAD_STRING ( reload_key, main, MAIN, MAIN_RELOAD_KEY );
	}

	void IniRead::Functions ( )
	{
		std::string function = g_File->szDirFile ( FUNCTIONS_PATH ).c_str ( );

		INIREAD_INT ( esp, function, FUNCTIONS, FUNCTIONS_ESP );
	}

	IniRead* g_IniRead = new IniRead;
}