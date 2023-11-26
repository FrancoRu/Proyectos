import mongoose from 'mongoose'

export type UserToken = {
  _id: mongoose.Schema.Types.ObjectId
  username: string
  email: string
}

export enum Importance {
  Low = 'Low',
  Medium = 'Medium',
  High = 'High'
}
export enum State {
  WithoutStarting = 'Without Starting',
  Developing = 'Developing',
  Finished = 'Finished'
}

export interface tasks {
  proyect: string
  createdBy: string
  user: mongoose.Schema.Types.ObjectId
  title: string
  description?: string
  assignedTo: string
  deadline: Date
  importance: Importance
}

export interface saveTasks extends tasks {
  state: State
}
