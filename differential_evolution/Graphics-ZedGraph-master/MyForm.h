#pragma once
#include <math.h>
#include <array>
#include <list>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "../differential_evolution/Generation.h"

std::list<Generation> species; 
namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label_x_min;
	private: System::Windows::Forms::TextBox^ textBox_x_min;
	private: System::Windows::Forms::Label^ label_x_max;
	private: System::Windows::Forms::TextBox^ textBox_x_max;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^ textBox_generation_size;
	private: System::Windows::Forms::TextBox^ textBox_y_max;
	private: System::Windows::Forms::Label^ label_y_max;
	private: System::Windows::Forms::TextBox^ textBox_y_min;
	private: System::Windows::Forms::Label^ label_y_min;
	private: ZedGraph::ZedGraphControl^ zedGraphControl1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox_mutation_power;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox_crossing_over_probability;
	private: System::Windows::Forms::Button^ button_new_multiple_gen;
	private: System::Windows::Forms::TextBox^ textBox_generations_number;
	private: System::Windows::Forms::Button^ button_previous;
	private: System::Windows::Forms::Button^ button_next;
	private: System::Windows::Forms::Button^ button_cycle;
	private: System::Windows::Forms::Button^ button_create;
	private: System::Windows::Forms::Button^ button_create_new_generation;

	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::Button^ button_Home;
	private: System::Windows::Forms::TextBox^ textBox_range;
	private: System::Windows::Forms::Label^ label_range;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ textBox_fittest;
	private: System::Windows::Forms::Label^ label4;

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label_x_min = (gcnew System::Windows::Forms::Label());
			this->textBox_x_min = (gcnew System::Windows::Forms::TextBox());
			this->label_x_max = (gcnew System::Windows::Forms::Label());
			this->textBox_x_max = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_generation_size = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y_max = (gcnew System::Windows::Forms::TextBox());
			this->label_y_max = (gcnew System::Windows::Forms::Label());
			this->textBox_y_min = (gcnew System::Windows::Forms::TextBox());
			this->label_y_min = (gcnew System::Windows::Forms::Label());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_mutation_power = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_crossing_over_probability = (gcnew System::Windows::Forms::TextBox());
			this->button_new_multiple_gen = (gcnew System::Windows::Forms::Button());
			this->textBox_generations_number = (gcnew System::Windows::Forms::TextBox());
			this->button_previous = (gcnew System::Windows::Forms::Button());
			this->button_next = (gcnew System::Windows::Forms::Button());
			this->button_cycle = (gcnew System::Windows::Forms::Button());
			this->button_create = (gcnew System::Windows::Forms::Button());
			this->button_create_new_generation = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->button_Home = (gcnew System::Windows::Forms::Button());
			this->textBox_range = (gcnew System::Windows::Forms::TextBox());
			this->label_range = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_fittest = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_x_min
			// 
			this->label_x_min->AutoSize = true;
			this->label_x_min->Location = System::Drawing::Point(137, 22);
			this->label_x_min->Name = L"label_x_min";
			this->label_x_min->Size = System::Drawing::Size(34, 13);
			this->label_x_min->TabIndex = 3;
			this->label_x_min->Text = L"x_min";
			// 
			// textBox_x_min
			// 
			this->textBox_x_min->Location = System::Drawing::Point(177, 19);
			this->textBox_x_min->Name = L"textBox_x_min";
			this->textBox_x_min->Size = System::Drawing::Size(25, 20);
			this->textBox_x_min->TabIndex = 4;
			this->textBox_x_min->Text = L"0";
			// 
			// label_x_max
			// 
			this->label_x_max->AutoSize = true;
			this->label_x_max->Location = System::Drawing::Point(208, 22);
			this->label_x_max->Name = L"label_x_max";
			this->label_x_max->Size = System::Drawing::Size(37, 13);
			this->label_x_max->TabIndex = 5;
			this->label_x_max->Text = L"x_max";
			// 
			// textBox_x_max
			// 
			this->textBox_x_max->Location = System::Drawing::Point(251, 19);
			this->textBox_x_max->Name = L"textBox_x_max";
			this->textBox_x_max->Size = System::Drawing::Size(25, 20);
			this->textBox_x_max->TabIndex = 6;
			this->textBox_x_max->Text = L"1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(45, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Generation size";
			// 
			// textBox_generation_size
			// 
			this->textBox_generation_size->Location = System::Drawing::Point(131, 19);
			this->textBox_generation_size->Name = L"textBox_generation_size";
			this->textBox_generation_size->Size = System::Drawing::Size(60, 20);
			this->textBox_generation_size->TabIndex = 8;
			this->textBox_generation_size->Text = L"200";
			// 
			// textBox_y_max
			// 
			this->textBox_y_max->Location = System::Drawing::Point(251, 45);
			this->textBox_y_max->Name = L"textBox_y_max";
			this->textBox_y_max->Size = System::Drawing::Size(25, 20);
			this->textBox_y_max->TabIndex = 13;
			this->textBox_y_max->Text = L"1";
			// 
			// label_y_max
			// 
			this->label_y_max->AutoSize = true;
			this->label_y_max->Location = System::Drawing::Point(208, 48);
			this->label_y_max->Name = L"label_y_max";
			this->label_y_max->Size = System::Drawing::Size(37, 13);
			this->label_y_max->TabIndex = 12;
			this->label_y_max->Text = L"y_max";
			// 
			// textBox_y_min
			// 
			this->textBox_y_min->Location = System::Drawing::Point(177, 45);
			this->textBox_y_min->Name = L"textBox_y_min";
			this->textBox_y_min->Size = System::Drawing::Size(25, 20);
			this->textBox_y_min->TabIndex = 11;
			this->textBox_y_min->Text = L"0";
			// 
			// label_y_min
			// 
			this->label_y_min->AutoSize = true;
			this->label_y_min->Location = System::Drawing::Point(137, 48);
			this->label_y_min->Name = L"label_y_min";
			this->label_y_min->Size = System::Drawing::Size(34, 13);
			this->label_y_min->TabIndex = 10;
			this->label_y_min->Text = L"y_min";
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(12, 12);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(493, 500);
			this->zedGraphControl1->TabIndex = 0;
			this->zedGraphControl1->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl1_Load);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(45, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Mutation power";
			// 
			// textBox_mutation_power
			// 
			this->textBox_mutation_power->Location = System::Drawing::Point(131, 45);
			this->textBox_mutation_power->Name = L"textBox_mutation_power";
			this->textBox_mutation_power->Size = System::Drawing::Size(60, 20);
			this->textBox_mutation_power->TabIndex = 15;
			this->textBox_mutation_power->Text = L"0,5";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Crossing-over probabilty";
			// 
			// textBox_crossing_over_probability
			// 
			this->textBox_crossing_over_probability->Location = System::Drawing::Point(131, 71);
			this->textBox_crossing_over_probability->Name = L"textBox_crossing_over_probability";
			this->textBox_crossing_over_probability->Size = System::Drawing::Size(60, 20);
			this->textBox_crossing_over_probability->TabIndex = 17;
			this->textBox_crossing_over_probability->Text = L"0,95";
			// 
			// button_new_multiple_gen
			// 
			this->button_new_multiple_gen->Location = System::Drawing::Point(511, 84);
			this->button_new_multiple_gen->Name = L"button_new_multiple_gen";
			this->button_new_multiple_gen->Size = System::Drawing::Size(150, 30);
			this->button_new_multiple_gen->TabIndex = 18;
			this->button_new_multiple_gen->Text = L"Create multiple generations";
			this->button_new_multiple_gen->UseVisualStyleBackColor = true;
			this->button_new_multiple_gen->Click += gcnew System::EventHandler(this, &MyForm::button_new_multiple_gen_Click);
			// 
			// textBox_generations_number
			// 
			this->textBox_generations_number->Location = System::Drawing::Point(667, 90);
			this->textBox_generations_number->Name = L"textBox_generations_number";
			this->textBox_generations_number->Size = System::Drawing::Size(50, 20);
			this->textBox_generations_number->TabIndex = 19;
			this->textBox_generations_number->Text = L"1";
			// 
			// button_previous
			// 
			this->button_previous->Location = System::Drawing::Point(511, 120);
			this->button_previous->Name = L"button_previous";
			this->button_previous->Size = System::Drawing::Size(70, 30);
			this->button_previous->TabIndex = 20;
			this->button_previous->Text = L"Previous";
			this->button_previous->UseVisualStyleBackColor = true;
			// 
			// button_next
			// 
			this->button_next->Location = System::Drawing::Point(591, 120);
			this->button_next->Name = L"button_next";
			this->button_next->Size = System::Drawing::Size(70, 30);
			this->button_next->TabIndex = 21;
			this->button_next->Text = L"Next";
			this->button_next->UseVisualStyleBackColor = true;
			// 
			// button_cycle
			// 
			this->button_cycle->Location = System::Drawing::Point(511, 156);
			this->button_cycle->Name = L"button_cycle";
			this->button_cycle->Size = System::Drawing::Size(150, 30);
			this->button_cycle->TabIndex = 22;
			this->button_cycle->Text = L"Cycle";
			this->button_cycle->UseVisualStyleBackColor = true;
			// 
			// button_create
			// 
			this->button_create->Location = System::Drawing::Point(511, 12);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(150, 30);
			this->button_create->TabIndex = 23;
			this->button_create->Text = L"Create";
			this->button_create->UseVisualStyleBackColor = true;
			this->button_create->Click += gcnew System::EventHandler(this, &MyForm::button_create_Click);
			// 
			// button_create_new_generation
			// 
			this->button_create_new_generation->Location = System::Drawing::Point(511, 48);
			this->button_create_new_generation->Name = L"button_create_new_generation";
			this->button_create_new_generation->Size = System::Drawing::Size(150, 30);
			this->button_create_new_generation->TabIndex = 24;
			this->button_create_new_generation->Text = L"Create next generation";
			this->button_create_new_generation->UseVisualStyleBackColor = true;
			this->button_create_new_generation->Click += gcnew System::EventHandler(this, &MyForm::button_create_new_generation_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(6, 21);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(125, 17);
			this->checkBox1->TabIndex = 28;
			this->checkBox1->Text = L"Rosenbrock function";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(6, 47);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(92, 17);
			this->checkBox2->TabIndex = 29;
			this->checkBox2->Text = L"Icicle function";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// button_Home
			// 
			this->button_Home->Location = System::Drawing::Point(511, 238);
			this->button_Home->Name = L"button_Home";
			this->button_Home->Size = System::Drawing::Size(150, 30);
			this->button_Home->TabIndex = 30;
			this->button_Home->Text = L"Home";
			this->button_Home->UseVisualStyleBackColor = true;
			this->button_Home->Click += gcnew System::EventHandler(this, &MyForm::button_Home_Click);
			// 
			// textBox_range
			// 
			this->textBox_range->Location = System::Drawing::Point(51, 19);
			this->textBox_range->Name = L"textBox_range";
			this->textBox_range->Size = System::Drawing::Size(93, 20);
			this->textBox_range->TabIndex = 31;
			// 
			// label_range
			// 
			this->label_range->AutoSize = true;
			this->label_range->Location = System::Drawing::Point(6, 22);
			this->label_range->Name = L"label_range";
			this->label_range->Size = System::Drawing::Size(39, 13);
			this->label_range->TabIndex = 32;
			this->label_range->Text = L"Range";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox_fittest);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label_range);
			this->groupBox1->Controls->Add(this->textBox_range);
			this->groupBox1->Location = System::Drawing::Point(511, 274);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(150, 90);
			this->groupBox1->TabIndex = 33;
			this->groupBox1->TabStop = false;
			// 
			// textBox_fittest
			// 
			this->textBox_fittest->Location = System::Drawing::Point(51, 52);
			this->textBox_fittest->Name = L"textBox_fittest";
			this->textBox_fittest->Size = System::Drawing::Size(93, 20);
			this->textBox_fittest->TabIndex = 34;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 55);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 33;
			this->label4->Text = L"Fittest";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBox1);
			this->groupBox2->Controls->Add(this->checkBox2);
			this->groupBox2->Controls->Add(this->textBox_x_min);
			this->groupBox2->Controls->Add(this->label_x_min);
			this->groupBox2->Controls->Add(this->label_y_min);
			this->groupBox2->Controls->Add(this->textBox_y_min);
			this->groupBox2->Controls->Add(this->label_x_max);
			this->groupBox2->Controls->Add(this->textBox_x_max);
			this->groupBox2->Controls->Add(this->label_y_max);
			this->groupBox2->Controls->Add(this->textBox_y_max);
			this->groupBox2->Location = System::Drawing::Point(12, 518);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(280, 100);
			this->groupBox2->TabIndex = 34;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Objective function";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->textBox_generation_size);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->textBox_mutation_power);
			this->groupBox3->Controls->Add(this->textBox_crossing_over_probability);
			this->groupBox3->Location = System::Drawing::Point(298, 518);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(207, 100);
			this->groupBox3->TabIndex = 35;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Population";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(722, 629);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button_Home);
			this->Controls->Add(this->button_create_new_generation);
			this->Controls->Add(this->button_create);
			this->Controls->Add(this->button_cycle);
			this->Controls->Add(this->button_next);
			this->Controls->Add(this->button_previous);
			this->Controls->Add(this->textBox_generations_number);
			this->Controls->Add(this->button_new_multiple_gen);
			this->Controls->Add(this->zedGraphControl1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		PointPairList^ boundaries_point_list = gcnew ZedGraph::PointPairList();
		int generation_number, generation_size;
		int genome_size = 2;
		double (*objective_function)(std::vector<double>);

	private: System::Void zedGraphControl1_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void button_create_Click(System::Object^ sender, System::EventArgs^ e) {
		//initialization
		generation_size = Convert::ToInt32(textBox_generation_size->Text);
		std::vector<std::pair<double, double>> bounds(genome_size);
		generation_number = 0;

		// Записываем точки гранциы
		bounds[0].first = Convert::ToDouble(textBox_x_min->Text);
		bounds[0].second = Convert::ToDouble(textBox_x_max->Text);
		bounds[1].first = Convert::ToDouble(textBox_y_min->Text);
		bounds[1].second = Convert::ToDouble(textBox_y_max->Text);
		Generation::setBoundaries(bounds);

			
		// Создаём стартовое поколение
		Generation origin(generation_size, genome_size);

		// Вывод range
		std::ostringstream ost;
		ost << std::scientific << origin.getRange();
		System::String^ s = gcnew System::String(ost.str().c_str());
		textBox_range->Text = s;

		// Вывод fittest 
		/*
		Individual fit1(origin.getFittest(horrific_function));
		textBox_fittest->Text = "(";
		textBox_fittest->Text += Convert::ToString(fit1[0]);
		textBox_fittest->Text += ", ";
		textBox_fittest->Text += Convert::ToString(fit1[1]);
		textBox_fittest->Text += ")";
		*/
		

		// Записываем силу мутации и вероятность кроссинговера
		origin.setMutationPower(Convert::ToDouble(textBox_mutation_power->Text));
		origin.setCrossoverProbablity(Convert::ToDouble(textBox_crossing_over_probability->Text));
		species.push_back(origin);
			
		//
		GraphPane^ panel = zedGraphControl1->GraphPane;

		// Список точек
		PointPairList^ origin_generation_point_list = gcnew ZedGraph::PointPairList();
		for (int i = 0; i < generation_size; i++)
		{
			//Добавление на график
			origin_generation_point_list->Add(origin[i][0], origin[i][1]);
		}
		LineItem^ CurveGeneration = panel->AddCurve("generation #0", origin_generation_point_list, Color::Green, SymbolType::Plus);
		CurveGeneration->Line->IsVisible = false;
		CurveGeneration->Symbol->Size = 7;


		// Рисуем границу
		boundaries_point_list->Clear();
		boundaries_point_list->Add(bounds[0].first, bounds[1].first);
		boundaries_point_list->Add(bounds[0].second, bounds[1].first);
		boundaries_point_list->Add(bounds[0].second, bounds[1].second);
		boundaries_point_list->Add(bounds[0].first, bounds[1].second);
		boundaries_point_list->Add(bounds[0].first, bounds[1].first);
		LineItem^ СurveBoundaries = panel->AddCurve("", boundaries_point_list, Color::Black, SymbolType::None);
		//generation_points_list.push_back(origin_generation_list);
			
		// Интервал, где есть данные
		double xmin = std::min(bounds[0].first, bounds[1].first);
		double xmax = std::max(bounds[0].second, bounds[1].second);
			
		// Устанавливаем интересующие нас интервалы по осям X и Y
		panel->XAxis->Scale->Min = xmin;
		panel->XAxis->Scale->Max = xmax;
		panel->YAxis->Scale->Min = xmin;
		panel->YAxis->Scale->Max = xmax;
			
		// Обновляем оси
		zedGraphControl1->AxisChange();
		// Обновляем график
		zedGraphControl1->Invalidate();
	}
	private: System::Void button_create_new_generation_Click(System::Object^ sender, System::EventArgs^ e) {
		// Создаём новое поколение
		Generation new_generation;
		new_generation  = species.back().createNewGeneation(horrific_function);

		// Вывод range
		std::ostringstream ost;
		ost << std::scientific << new_generation.getRange();
		System::String^ s = gcnew System::String(ost.str().c_str());
		textBox_range->Text = s;

		// Записываем список точек для графика
		PointPairList^ new_generation_point_list = gcnew ZedGraph::PointPairList();
		for (int i = 0; i < generation_size; i++)
		{
			new_generation_point_list->Add(new_generation[i][0], new_generation[i][1]);
		}
		// Номер поколения
		generation_number++;
		System::String^ str_generation_number = "generation #";
		str_generation_number += generation_number;

		// Чистим график
		GraphPane^ panel = zedGraphControl1->GraphPane;
		panel->CurveList->Clear();

		//*gener = new_generation;
		species.push_back(new_generation);
		//species->at(generation_number) = new_generation;

		// Рисуем точки
		LineItem^ СurveBoundaries = panel->AddCurve("", boundaries_point_list, Color::Black, SymbolType::None);
		LineItem^ Curve1 = panel->AddCurve(str_generation_number, new_generation_point_list, Color::Green, SymbolType::Plus);
		Curve1->Line->IsVisible = false;
		Curve1->Symbol->Size = 7;

		// Обновляем график
		zedGraphControl1->Invalidate();
	}
	private: System::Void button_new_multiple_gen_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = Convert::ToDouble(textBox_generations_number->Text);
		Generation new_generation;
		for (int i = 0; i < n; i++) {
			new_generation = species.back().createNewGeneation(horrific_function);
			species.push_back(new_generation);
			generation_number++;
		}

		// Вывод range
		std::ostringstream ost;
		ost << std::scientific << new_generation.getRange();
		System::String^ s = gcnew System::String(ost.str().c_str());
		textBox_range->Text = s;

		// Записываем список точек для графика
		PointPairList^ new_generation_point_list = gcnew ZedGraph::PointPairList();
		for (int i = 0; i < generation_size; i++)
		{
			new_generation_point_list->Add(new_generation[i][0], new_generation[i][1]);
		}
		// Номер поколения
		System::String^ str_generation_number = "generation #";
		str_generation_number += generation_number;
	
		// Чистим график
		GraphPane^ panel = zedGraphControl1->GraphPane;
		panel->CurveList->Clear();
	
		//species->at(generation_number) = new_generation;
	
		// Рисуем точки
		LineItem^ СurveBoundaries = panel->AddCurve("", boundaries_point_list, Color::Black, SymbolType::None);
		LineItem^ Curve1 = panel->AddCurve(str_generation_number, new_generation_point_list, Color::Green, SymbolType::Plus);
		Curve1->Line->IsVisible = false;
		Curve1->Symbol->Size = 7;
	
		// Обновляем график
		zedGraphControl1->Invalidate();
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		checkBox2->Checked = false;
		objective_function = rosenbrock_function;
	}
	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		checkBox1->Checked = false;
		objective_function = icicle_function;
	}
	private: System::Void button_Home_Click(System::Object^ sender, System::EventArgs^ e) {
		std::vector<std::pair<double, double>> bounds(genome_size);

		// Записываем точки гранциы
		bounds[0].first = Convert::ToDouble(textBox_x_min->Text);
		bounds[0].second = Convert::ToDouble(textBox_x_max->Text);
		bounds[1].first = Convert::ToDouble(textBox_y_min->Text);
		bounds[1].second = Convert::ToDouble(textBox_y_max->Text);

		// Интервал, где есть данные
		double xmin = std::min(bounds[0].first, bounds[1].first);
		double xmax = std::max(bounds[0].second, bounds[1].second);
		GraphPane^ panel = zedGraphControl1->GraphPane;
		// Устанавливаем интересующие нас интервалы по осям X и Y
		panel->XAxis->Scale->Min = xmin;
		panel->XAxis->Scale->Max = xmax;
		panel->YAxis->Scale->Min = xmin;
		panel->YAxis->Scale->Max = xmax;

		zedGraphControl1->AxisChange();
		// Обновляем график
		zedGraphControl1->Invalidate();
	}
};
}
