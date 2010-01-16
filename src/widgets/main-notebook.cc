/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * player
 * Copyright (C)  2010  Esdras Beleza <linux@esdrasbeleza.com>
 * 
 * player is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * player is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "main-notebook.h"

MainNotebook::MainNotebook() {
	set_border_width(10);
	set_tab_pos(Gtk::POS_LEFT);

		
	Gtk::Label* testLabel1 = Gtk::manage(new Gtk::Label("Test label 1"));
	Gtk::Label* testLabel2 = Gtk::manage(new Gtk::Label("Test label 2"));
	Gtk::Label* testLabel3 = Gtk::manage(new Gtk::Label("Test label 3"));
	

	append_page(*testLabel1, "Context");
	append_page(*testLabel2, "Collection");
	append_page(*testLabel3, "Playlists");
	
	// For each page, set it the label angle for 90 degrees
	for (int curr_page_num = 0; curr_page_num < get_n_pages(); curr_page_num++) {
		Gtk::Widget* curr_page       = get_nth_page(curr_page_num);
		Gtk::Label* curr_page_label  = (Gtk::Label*)get_tab_label(*curr_page);
		curr_page_label->set_angle(90);
	}
	
	
	show_all();
	
}


MainNotebook::~MainNotebook() {
}
